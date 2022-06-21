using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMovment : MonoBehaviour
{

    private float xRot;
    private Vector3 PlayerMoveInput;
    private Vector2 PlayerMouseInput;

    public LayerMask FloorMask;
    public Transform GroundCheck;
    public Transform PlayerCamera;
    public Rigidbody PlayerBody;
    public float Speed;
    public float Sens;
    public float Jump;
    public float hp = 200;

    void Update()
    {
        PlayerMoveInput = new Vector3(Input.GetAxis("Horizontal"), 0f, Input.GetAxis("Vertical"));

        MovePlayer();
    }

    private void MovePlayer(){
        Vector3 MoveVector = transform.TransformDirection(PlayerMoveInput) * Speed;
        PlayerBody.velocity = new Vector3(MoveVector.x, PlayerBody.velocity.y, MoveVector.z);

        if(Input.GetKeyDown(KeyCode.Space)){
            if(Physics.CheckSphere(GroundCheck.position, .1f, FloorMask)){
                PlayerBody.AddForce(Vector3.up * Jump, ForceMode.Impulse);
            }            
        }
    }


    public void Life(int damage){
        hp -= damage;
         
        Debug.Log(hp);

        //  if(hp <= 0){
        //      GetComponent<PlayerMovment>().enabled = false;
        //  }
    }
}
