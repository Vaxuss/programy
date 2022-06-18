using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class BulletController : MonoBehaviour
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
        gameObject.transform.Rotate(90, 0, 0, Space.Self);  
        Setup();
    }

    // void Explode(){

    //     Collider[] enemies = Physics.OverlapSphere(transform.position, explosionRange, enemy);
        
    //     for (int i = 0; i < enemies.Length; i++)
    //     {
    //         if(enemies[i].GetComponent<Rigidbody>()){
    //             enemies[i].GetComponent<Rigidbody>().AddExplosionForce(explosionForce, transform.position, explosionRange);
    //         } 
            
    //     }
        
    // }

    void Delay(){
        Destroy(gameObject);
    }

    // void OnCollisionEnter(Collision collision)
    // {
    //     foreach (ContactPoint contact in collision.contacts)
    //     {
    //         if(explosion != null) Instantiate(explosion, transform.position, Quaternion.identity);
    //     }
    // }

    public void OnTriggerEnter(Collider other) {
        if(explosion != null) Instantiate(explosion, transform.position, Quaternion.identity);
        if(other.tag == "Enemy" || other.tag == "Ground" || other.tag == "Wall"){
            other.GetComponent<ShootingAi>().TakeDamage(explosionDamage);
            Debug.Log("Trafiony");
            Invoke("Delay", 0.05f);
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
    void FixedUpdate()
    {
        maxLifetime -= Time.deltaTime;
        if(maxLifetime <= 0) Invoke("Delay", 0.05f);//Explode();
    }

    private void OnDrawGizmosSelected() {
        Gizmos.color = Color.red;
        Gizmos.DrawWireSphere(transform.position, explosionRange);
    }
}
