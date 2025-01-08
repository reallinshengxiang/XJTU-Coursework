using System.Collections;
using System.Collections.Generic;
using JetBrains.Annotations;
using Unity.Collections.LowLevel.Unsafe;
using Unity.VisualScripting;
using UnityEngine;
public class NewBehaviourScript1 : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
    }
    // Update is called once per frame
    void Update()
    {
        Vector2 p=transform.localPosition;
        if(Mathf.Abs(p.y)<=100&&Mathf.Abs(p.x)<=100)
        {
            p.y+=transform.up.y*40f*Time.smoothDeltaTime;
            p.x+=transform.up.x*40f*Time.smoothDeltaTime;
            transform.localPosition=p;
        }        
        if(Mathf.Abs(p.y)>100||Mathf.Abs(p.x)>100)
        {
            NewBehaviourScript3.esum-=1;
            Destroy(gameObject);
        }
        if(NewBehaviourScript3.sumplane<=9)
        {
           GameObject e = Instantiate(Resources.Load("Prefabs/Plane") as GameObject); // Prefab MUST BE locaed in Resources/Prefab folder!
	       Vector3 h=e.transform.localPosition;
           h.x=Random.Range(-90,90);
           h.y=Random.Range(-90,90);
           e.transform.localPosition=h;
           NewBehaviourScript3.sumplane+=1;
        }
    }
    private void OnCollisionEnter2D(Collision2D collision)
    {
        if(gameObject.tag=="Egg"&&collision.gameObject.tag=="Plane")
        {
            NewBehaviourScript3.esum-=1;
            if(collision.gameObject.GetComponent<Renderer>().material.color.a>0.6f)
            {
                collision.gameObject.GetComponent<Renderer>().material.color = new Color(
                collision.gameObject.GetComponent<Renderer>().material.color.r,
                collision.gameObject.GetComponent<Renderer>().material.color.g,
                collision.gameObject.GetComponent<Renderer>().material.color.b, 
                collision.gameObject.GetComponent<Renderer>().material.color.a*0.8f);
            }
            else
            {
                Destroy(collision.gameObject);
                NewBehaviourScript3.dsum+=1;  
                NewBehaviourScript3.sumplane-=1;
            }    
            Destroy(gameObject);                
            if(NewBehaviourScript3.sumplane<=9)
            {
               GameObject e = Instantiate(Resources.Load("Prefabs/Plane") as GameObject); // Prefab MUST BE locaed in Resources/Prefab folder!
	           Vector3 h=e.transform.localPosition;
               h.x=Random.Range(-90,90);
               h.y=Random.Range(-90,90);
               e.transform.localPosition=h;
               NewBehaviourScript3.sumplane+=1;
            }
        }
        else if(gameObject.tag=="Egg"&&collision.gameObject.tag=="Egg")
        {
            Destroy(gameObject);
            Destroy(collision.gameObject);
            NewBehaviourScript3.esum=NewBehaviourScript3.esum-2;
        }
    }
}
