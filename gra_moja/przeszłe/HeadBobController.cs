// using System.Collections;
// using System.Collections.Generic;
// using UnityEngine;

// public class HeadBobController : MonoBehaviour
// {
//     [SerializeField] private bool _enable = true;

//     [SerializeField, Range(0, 0.1f)] private float amp = 0.015f;
//     [SerializeField, Range(0, 30)] private float freq = 10.0f;

//     [SerializeField] private Transform cam = null;
//     [SerializeField] private Transform camHold = null;

//     private float toggleSpeed = 3.0f;
//     private Vector3 startPos;
//     private CharacterController controller;
//     // Start is called before the first frame update
//     void Start()
//     {
//         controller = GetComponent<CharacterController>();
//         startPos = cam.localPosition;
//     }

//     // Update is called once per frame
//     void Update()
//     {
//         if (!_enable) return;

//         CheckMotion();
//         ResetPos();
//         cam.LookAt(FocusTarget());
//     }

//     private void CheckMotion(){
//         float speed = new Vector3(controller.velocity.x, 0 , controller.velocity.z).magnitude;

//         if(speed < toggleSpeed) return;

//         PlayMotion(FootStepMotion());
//     }

//     private void ResetPos(){
//         if(cam.localPosition == startPos) return;
//         cam.localPosition = Vector3.Lerp(cam.localPosition, startPos, 1 * Time.deltaTime);
//     }

//     private Vector3 FootStepMotion(){
//         Vector3 pos = Vector3.zero;
//         pos.y += Mathf.Sin(Time.time * freq) * amp;
//         pos.x += Mathf.Cos(Time.time * freq / 2 ) * amp * 2;
//         return pos;
//     }

//     void PlayMotion(Vector3 motion){
//         cam.localPosition += motion; 
//     }

//     private Vector3 FocusTarget(){
//         Vector3 pos = new Vector3(transform.position.x, transform.position.y + camHold.localPosition.y, transform.position.z);
//         pos += camHold.forward * 15.0f;
//         return pos;
//     }
// }
