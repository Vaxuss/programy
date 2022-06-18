using UnityEngine;
using UnityEngine.AI;
using System.Collections;
using System.Collections.Generic;
using System;

public class ShootingAi : MonoBehaviour
{
    public NavMeshAgent agent;
    public Transform player;
    public LayerMask Ground, whatIsPlayer, Obstruction;
    public bool isMelee;
    public float Speed = 32f;
    private float CurrentSpeed;
    public float health;
    public Rigidbody rb;
    

    //walking
    public Vector3 walkPoint;
    bool walkPointSet;
    public float walkPointRange;

    //Attacking
    public float timeBetweenAttacks;
    bool alreadyAttacked;
    public GameObject projectile;

    //States
    public bool canSeePlayer;
    public float sightRange, attackRange;
    public bool playerInSightRange, playerInSight, playerInAttackRange;
    

    void Start()
    {
        player = GameObject.Find("Player").transform;
        agent = GetComponent<NavMeshAgent>();
    }
    
    void FixedUpdate()
    {
        // Raycast sight;
        // if(Physics.Raycast(transform.position, transform.player))

        //Check if player is in range for sight and attack;
        playerInSightRange = Physics.CheckSphere(transform.position, sightRange, whatIsPlayer);
        playerInAttackRange = Physics.CheckSphere(transform.position, attackRange, whatIsPlayer);

        Sight();

        if(!playerInSightRange && !playerInAttackRange) Patroling();
        if(playerInSightRange && !playerInAttackRange && canSeePlayer) ChasePlayer();
        if(playerInSightRange && playerInAttackRange && canSeePlayer) AttackPlayer();

    }

    void Sight(){
        Vector3 directionToTarget = (player.position - transform.position).normalized;
        float distanceToTarget = Vector3.Distance(transform.position, player.position);
        if (!Physics.Raycast(transform.position, directionToTarget, distanceToTarget, Obstruction))
                    canSeePlayer = true;
                else
                    canSeePlayer = false;
    }

    void Patroling(){
        if(!walkPointSet) SearchWalkPoint();

        if(walkPointSet) agent.SetDestination(walkPoint);

        Vector3 distanceToWalkPoint = transform.position - walkPoint;

        if(distanceToWalkPoint.magnitude < 1f) walkPointSet = false;
    }

    void SearchWalkPoint(){
        //Calculate random patrolling path
        float randomZ = UnityEngine.Random.Range(-walkPointRange, walkPointRange);
        float randomX = UnityEngine.Random.Range(-walkPointRange, walkPointRange);

        walkPoint = new Vector3(transform.position.x + randomX, transform.position.y, transform.position.z + randomZ);
        if(Physics.Raycast(walkPoint, -transform.up, 2f, Ground)) walkPointSet = true;
    }

    void ChasePlayer(){
        agent.SetDestination(player.position);
        transform.LookAt(player);
    }

    void AttackPlayer(){
        agent.SetDestination(transform.position);

        transform.LookAt(player);

        if(!alreadyAttacked){
            
            //atacking
            if(isMelee == false){
                rb = Instantiate(projectile, transform.position, Quaternion.identity).GetComponent<Rigidbody>();
                rb.AddForce(transform.forward * 32f, ForceMode.Impulse);
                //rb.AddForce(transform.up * 8f, ForceMode.Impulse);
            }
            else{
               
            }
            
            alreadyAttacked = true;
            Invoke(nameof(ResetAttack), timeBetweenAttacks);
        }
    }

    void ResetAttack() {
        rb.velocity = transform.forward * 10f;
        alreadyAttacked = false;
    }

    public void TakeDamage(int damage){
        health -= damage;
        Debug.Log("Dostal damage");
        if(health <= 0) 
            Invoke(nameof(DestroyEnemy), 0.01f);
    }

    void DestroyEnemy(){
        Destroy(gameObject);
    }

    private void OnDrawGizmosSelected() {
        Gizmos.color = Color.red;
        Gizmos.DrawWireSphere(transform.position, attackRange);
        Gizmos.color = Color.yellow;
        Gizmos.DrawWireSphere(transform.position, sightRange);
    }

    public void OnTriggerEnter(Collider other) {
        if(other.tag == "Player"){
            other.GetComponent<PlayerMovment>().Life(100);
            Debug.Log("TrafionyGraczMelee");
        }
    }
}
