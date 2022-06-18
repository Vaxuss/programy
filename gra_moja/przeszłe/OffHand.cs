using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class OffHand : MonoBehaviour
{
    public GameObject bullet;

    public float shootForce, upwardForce;

    public float timeBetweenShots, spread, reloadTime, timeBetweenShooting;
    public int magSize, bulletsPerTap;
    public bool allowButtonHold;

    int bulletsLeft, bulletShot;

    bool shooting, readyToShoot, reloading;


    public Camera fpsCam;
    public Transform attackPoint;

    public GameObject muzzleFlash;
    public TextMeshProUGUI ammunitionDisplay;

    public bool allowInvoke = true;
    void Start()
    {
        bullet.transform.position = new Vector3(-1000, 0, 0);
        bulletsLeft = magSize;
        readyToShoot = true;
    }

    void Update()
    {
        MyInput();

        if(ammunitionDisplay != null) ammunitionDisplay.SetText(bulletsLeft / bulletsPerTap + " / " + magSize / bulletsPerTap);
    }

    void MyInput(){
        if(allowButtonHold) shooting = Input.GetKey(KeyCode.LeftControl);
        else shooting = Input.GetKeyDown(KeyCode.LeftControl);

        if(readyToShoot && shooting && !reloading && bulletsLeft <=0 ) Reload();

        //shooting
        if(readyToShoot && shooting && !reloading && bulletsLeft > 0){
            bulletShot = 0;
            Shoot();
        }
    }

    void Shoot(){
        readyToShoot = false;

        bullet.transform.position = new Vector3(0, 0, 0);

        Ray ray = fpsCam.ViewportPointToRay(new Vector3(0.5f, 0.5f, 0));
        RaycastHit hit;

        Vector3 targetPoint;
        if(Physics.Raycast(ray, out hit)) 
            targetPoint = hit.point;
        else 
            targetPoint = ray.GetPoint(75);

        Vector3 directionWithoutSpread = targetPoint - attackPoint.position;

        float x = Random.Range(-spread, spread);
        float y = Random.Range(-spread, spread);

        Vector3 directionWithSpread = directionWithoutSpread + new Vector3(x,y,0);

        GameObject currentBullet = Instantiate(bullet, attackPoint.position, Quaternion.identity);
        currentBullet.transform.forward = directionWithSpread.normalized;

        //Adding force to the bullet
        currentBullet.GetComponent<Rigidbody>().AddForce(directionWithSpread.normalized * shootForce, ForceMode.Impulse);
        currentBullet.GetComponent<Rigidbody>().AddForce(fpsCam.transform.up * upwardForce, ForceMode.Impulse);

        if(muzzleFlash != null) 
            Instantiate(muzzleFlash, attackPoint.position, Quaternion.identity);

        bulletsLeft--;
        bulletShot++;

        if(allowInvoke){
            Invoke("ResetShot", timeBetweenShooting);
            allowInvoke = false;
        }
        //more shoots per triggerpull eg. shotgun burst
        if(bulletShot < bulletsPerTap && bulletsLeft > 0) Invoke("Shoot", timeBetweenShots);
    }

    void ResetShot(){
        readyToShoot = true;
        allowInvoke = true;
    }

    private void Reload(){
        bullet.transform.position = new Vector3(-1000, 0, 0);
        reloading = true;
        Invoke("ReloadFinished", reloadTime);  
    }

    private void ReloadFinished(){
        Debug.Log("Trafiony");
        bulletsLeft = magSize;
        reloading = false;
    }
}
