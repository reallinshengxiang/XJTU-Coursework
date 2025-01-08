using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class NewBehaviourScript : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        Vector3 p = transform.localPosition;
        if(Input.GetKey(KeyCode.UpArrow)&&p.x>-50&&p.y<50)
        {
            p.x-=0.23f;
            if(p.x<-50) p.x=-50;
            p.y=-p.x;
            if(transform.localScale.x<6)
            {
               float s = Input.GetAxis("Vertical") * 0.1f;
               Vector3 size = new Vector3(s, s, s);
               transform.localScale += size;          
            }   
            else
            {
                Vector3 size = new Vector3(6,6,6);
                transform.localScale =size;
            }
            transform.localPosition=p;       
        }   
        else if(Input.GetKey(KeyCode.DownArrow)&&p.x<-1&&p.y>1)
        {
            p.x+=0.23f;
            if(p.x>-1) p.x=-1;
            p.y=-p.x;
            if(transform.localScale.x>1)
            {
               float s = Input.GetAxis("Vertical") * 0.1f;
               Vector3 size = new Vector3(s, s, s);
               transform.localScale += size;          
            }   
            else
            {
                Vector3 size = new Vector3(1,1,1);
                transform.localScale =size;
            }
            transform.localPosition=p;   
        }  
        else if(Input.GetKey(KeyCode.Q)) 
        {
            Application.Quit();
        }
    }
}