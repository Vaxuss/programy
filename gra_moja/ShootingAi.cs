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
    public float Speed = 10f;
    public float health;
    public Rigidbody rb;
    public bool canSeePlayer;
    

    //walking
    public Vector3 walkPoint;
    bool walkPointSet;
    public float walkPointRange;

    //Attacking
    public float timeBetweenAttacks;
    bool alreadyAttacked;
    public GameObject projectile;

    //States
    public float sightRange, attackRange;
    public bool playerInSightRange, playerInSight, playerInAttackRange;
    private Vector3 moveDirection = Vector3.zero;

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
        rb.AddForce(transform.forward * Speed);
        transform.LookAt(player);
    }

    void AttackPlayer(){
        agent.SetDestination(transform.position);

        transform.LookAt(player);

        if(!alreadyAttacked){
            
            //atacking
            if(!isMelee){
                rb = Instantiate(projectile, transform.position, Quaternion.identity).GetComponent<Rigidbody>();
                rb.AddForce(transform.forward * 100, ForceMode.Impulse);
                //rb.AddForce(transform.up * 8f, ForceMode.Impulse);
            }
            else{
                rb = gameObject.GetComponent<Rigidbody>();
                rb.AddForce(transform.forward * 1000, ForceMode.Impulse);
                Invoke("Delay", 1f);
            }
            

            alreadyAttacked = true;
            Invoke(nameof(ResetAttack), timeBetweenAttacks);
        }
    }

    void Delay(){
        rb.velocity = Vector3.zero;
    }

    void ResetAttack() {
        alreadyAttacked = false;
    }

    public void TakeDamage(int damage){
        health -= damage;
        Debug.Log("Dostal damage");
        if(health <= 0) 
            Invoke(nameof(DestroyEnemy), 0.01f);
        else
            Invoke("Delay", .5f);
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
