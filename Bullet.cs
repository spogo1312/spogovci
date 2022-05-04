using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
    public GameObject player;
    public BoxCollider2D collider2D;
    public float speed;
    public float dmg;
    public Rigidbody2D rb;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {

        
        rb.velocity = new Vector2(0 * speed ,player.transform.rotation.y * speed);
        transform.Translate((transform.forward * speed * Time.deltaTime));
    }
}
