using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class EnemyBullet : MonoBehaviour
{
    public Rigidbody rb;
    public GameObject explosion;
    public LayerMask enemy;
    

    [Range (0f,1f)]
    public float bounciness;
    public bool useGrav;
    
    public int explosionDamage;
    public float explosionRange;
    public float explosionForce;

    public int maxCollisions;
    public float maxLifetime;
    public bool explodeOnTouch = true;

    int collisions;
    PhysicMaterial physics_mat;

    void Start()
    {
        Setup();
    }

    void Explode(){

        Collider[] enemies = Physics.OverlapSphere(transform.position, explosionRange, enemy);
        
        for (int i = 0; i < enemies.Length; i++)
        {
            if(enemies[i].GetComponent<Rigidbody>()){
                enemies[i].GetComponent<Rigidbody>().AddExplosionForce(explosionForce, transform.position, explosionRange);
            } 
            
        }
        Invoke("Delay", 0.05f);
    }

    void Delay(){
        Destroy(gameObject);
    }

    public void OnTriggerEnter(Collider other) {
        collisions++;
        if(other.tag == "Player"){
            if(explosion != null) Instantiate(explosion, transform.position, Quaternion.identity);
            other.GetComponent<PlayerMovment>().Life(explosionDamage);
            Debug.Log("TrafionyGracz");
            Explode();
        }
    }

    void Setup(){
        physics_mat = new PhysicMaterial();
        physics_mat.bounciness = bounciness;
        physics_mat.frictionCombine = PhysicMaterialCombine.Minimum;
        physics_mat.bounceCombine = PhysicMaterialCombine.Maximum;

        GetComponent<BoxCollider>().material = physics_mat;

        rb.useGravity = useGrav;
    }

    // Update is called once per frame
    void Update()
    {
        if(collisions > maxCollisions) Explode();
        maxLifetime -= Time.deltaTime;
        if(maxLifetime <= 0) Explode();
    }

    private void OnDrawGizmosSelected() {
        Gizmos.color = Color.red;
        Gizmos.DrawWireSphere(transform.position, explosionRange);
    }
}
