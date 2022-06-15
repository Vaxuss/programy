using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class WeaponSway : MonoBehaviour
{
    [SerializeField] private float smooth;
    [SerializeField] private float swayMultiplier;

    void Update()
    {
        float X = Input.GetAxisRaw("Mouse X") * swayMultiplier;
        float Y = Input.GetAxisRaw("Mouse Y") * swayMultiplier;

        Quaternion rotX = Quaternion.AngleAxis(-Y, Vector3.right);
        Quaternion rotY = Quaternion.AngleAxis(X, Vector3.up); 

        Quaternion targetRot = rotX * rotY;

        transform.localRotation = Quaternion.Slerp(transform.localRotation, targetRot, smooth * Time.deltaTime);
    }
}
