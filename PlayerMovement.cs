using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMovement : MonoBehaviour
{
    public float rychlostPohybu;
    public Rigidbody2D rb;
    public GameObject gameObject;
    public Rigidbody2D bullet;
    bool rotaceR;
    bool rotaceL;
    bool rotaceD;
    bool rotaceU;
    

    private Vector2 smerPohybu;


    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        Vstup();
    }

    private void FixedUpdate()
    {
        Pohyb();
        Strelba();
    }

    void Vstup()
    {
        float pohybX = Input.GetAxis("Horizontal");
        float pohybY = Input.GetAxis("Vertical");
        smerPohybu = new Vector2(pohybX, pohybY).normalized;
        rotaceR = Input.GetKey(KeyCode.L);
        rotaceL = Input.GetKey(KeyCode.J);
        rotaceD = Input.GetKey(KeyCode.K);
        rotaceU = Input.GetKey(KeyCode.I);
    }

    void Pohyb() 
    {
        rb.velocity = new Vector2(smerPohybu.x * rychlostPohybu, smerPohybu.y * rychlostPohybu);
        if (rotaceR == true) 
        {
            gameObject.transform.eulerAngles = Vector3.forward * -90; 
        }
       
        if (rotaceL == true)
        {
            gameObject.transform.eulerAngles = Vector3.forward * 90;
        }
        
        if (rotaceU == true)
        {
            gameObject.transform.eulerAngles = Vector3.forward * 0;
        }
       
        if (rotaceD == true)
        {
            gameObject.transform.eulerAngles = Vector3.forward * 180;
        }
        if (rotaceR == true && rotaceU == true) 
        {
            gameObject.transform.eulerAngles = Vector3.forward * -45;
        }
        if (rotaceR == true && rotaceD == true) 
        {
            gameObject.transform.eulerAngles = Vector3.forward * -135;
        }
        if (rotaceL == true && rotaceD) 
        {
            gameObject.transform.eulerAngles = Vector3.forward * 135;
        }
        if(rotaceL == true && rotaceU) 
        {
            gameObject.transform.eulerAngles = Vector3.forward * 45;
        }
        
    }
    void Strelba() 
    {
        if (Input.GetKeyDown(KeyCode.Space))
        {
            Rigidbody2D clone;
            if (rotaceD || rotaceL || rotaceR || rotaceU)
            {
                clone = Instantiate(bullet, transform.position, transform.rotation);

                if (rotaceD == true)
                {

                    clone.velocity = new Vector3(0, -5);
                }
                if (rotaceU == true)
                {
                    clone.velocity = new Vector3(0, 5);
                }
                if (rotaceL == true)
                {
                    clone.velocity = new Vector3(-5, 0);
                }
                if (rotaceR == true)
                {
                    clone.velocity = new Vector3(5, 0);
                }
                if (rotaceR == true && rotaceD == true)
                {
                    clone.velocity = new Vector3(5, -5);
                }
                if (rotaceL == true && rotaceD == true)
                {
                    clone.velocity = new Vector3(-5, -5);
                }
                if (rotaceR == true && rotaceU == true)
                {
                    clone.velocity = new Vector3(5, 5);
                }
                if (rotaceL == true && rotaceU == true)
                {
                    clone.velocity = new Vector3(-5, 5);
                }
            }


        }
    }
}
