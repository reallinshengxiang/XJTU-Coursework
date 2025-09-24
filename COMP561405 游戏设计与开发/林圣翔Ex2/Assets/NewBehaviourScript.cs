using TMPro;
using UnityEngine;
public class GreenArrowBehavior : MonoBehaviour
{
    public float mHeroSpeed = 20f,a=5f;
    public float mHeroRotateSpeed=45; 

    private int mTotalEggCount = 0,flag=1;

    public TMP_Text mytext=null;

    // Start is called before the first frame update
    private void Start()
    {      
        NewBehaviourScript3.stime=NewBehaviourScript3.ntime;
        if(NewBehaviourScript3.sumplane<=9)
        {
           GameObject e = Instantiate(Resources.Load("Prefabs/Plane") as GameObject); // Prefab MUST BE locaed in Resources/Prefab folder!
	       Vector3 h=e.transform.localPosition;
           h.x=UnityEngine.Random.Range(-90,90);
           h.y=UnityEngine.Random.Range(-90,90);
           e.transform.localPosition=h;
           NewBehaviourScript3.sumplane+=1;
        }   
        mytext.text="HERO:Drive(Mouse) TouchEnemy("+NewBehaviourScript3.tsum.ToString()+")"+"      EGG:OnScreen("+NewBehaviourScript3.esum.ToString()+")"+"      ENEMY:Count("+NewBehaviourScript3.sumplane.ToString()+") Destoryed("+NewBehaviourScript3.dsum.ToString()+")";
    }

    // Update is called once per frame
    private void Update()
    {
        if(NewBehaviourScript3.sumplane<=9)
        {
           GameObject e = Instantiate(Resources.Load("Prefabs/Plane") as GameObject); // Prefab MUST BE locaed in Resources/Prefab folder!
	       Vector3 h=e.transform.localPosition;
           h.x=UnityEngine.Random.Range(-90,90);
           h.y=UnityEngine.Random.Range(-90,90);
           e.transform.localPosition=h;
           NewBehaviourScript3.sumplane+=1;
        }   
        if(Input.GetKeyDown(KeyCode.Q)) Application.Quit();
        else if(Input.GetKeyDown(KeyCode.M))  flag=-flag;
        else if(flag==1)
        {
            mytext.text="HERO:Drive(Mouse) TouchEnemy("+NewBehaviourScript3.tsum.ToString()+")"+"      EGG:OnScreen("+NewBehaviourScript3.esum.ToString()+")"+"      ENEMY:Count("+NewBehaviourScript3.sumplane.ToString()+") Destoryed("+NewBehaviourScript3.dsum.ToString()+")";
            Vector3 p = Camera.main.ScreenToWorldPoint(Input.mousePosition);
            p.z = 0f;
            transform.localPosition = p;
            if(Input.GetKey(KeyCode.RightArrow)||Input.GetKey(KeyCode.D)) transform.Rotate(Vector3.forward,-mHeroRotateSpeed*Time.smoothDeltaTime); 
            else if(Input.GetKey(KeyCode.LeftArrow)||Input.GetKey(KeyCode.A)) transform.Rotate(Vector3.forward,mHeroRotateSpeed*Time.smoothDeltaTime);
            if (Input.GetKey(KeyCode.Space))
            {              
                NewBehaviourScript3.ntime+=Time.deltaTime;
                if(NewBehaviourScript3.ntime-NewBehaviourScript3.stime>=0.2)
                {
                    NewBehaviourScript3.esum+=1;
                    GameObject e = Instantiate(Resources.Load("Prefabs/Egg") as GameObject); // Prefab MUST BE locaed in Resources/Prefab folder!
                    e.transform.localPosition = transform.localPosition;
                    e.transform.up=transform.up;
                    NewBehaviourScript3.ntime=NewBehaviourScript3.stime=0;
                }               
                //Debug.Log("Spawn Eggs:");
                // mTotalEggCount++;
            }
        }
        else if(flag==-1)
        {
            mytext.text="HERO:Drive(Key) TouchEnemy("+NewBehaviourScript3.tsum.ToString()+")"+"      EGG:OnScreen("+NewBehaviourScript3.esum.ToString()+")"+"      ENEMY:Count("+NewBehaviourScript3.sumplane.ToString()+") Destoryed("+NewBehaviourScript3.dsum.ToString()+")";
            Vector2 h=transform.position;
            if(Input.GetKey(KeyCode.RightArrow)||Input.GetKey(KeyCode.D)) transform.Rotate(Vector3.forward,-mHeroRotateSpeed*Time.smoothDeltaTime); 
            else if(Input.GetKey(KeyCode.LeftArrow)||Input.GetKey(KeyCode.A)) transform.Rotate(Vector3.forward,mHeroRotateSpeed*Time.smoothDeltaTime);          
            else if(Input.GetKey(KeyCode.UpArrow)||Input.GetKey(KeyCode.W))   mHeroSpeed+=a;
            else if(Input.GetKey(KeyCode.DownArrow)||Input.GetKey(KeyCode.S))   mHeroSpeed-=a; 
            h.x=h.x+mHeroSpeed*Time.smoothDeltaTime*transform.up.x;
            h.y=h.y+mHeroSpeed*Time.smoothDeltaTime*transform.up.y;
            transform.position=h;
            if (Input.GetKey(KeyCode.Space))
            {              
                NewBehaviourScript3.ntime+=Time.deltaTime;
                if(NewBehaviourScript3.ntime-NewBehaviourScript3.stime>=0.2)
                {
                    NewBehaviourScript3.esum+=1;
                    GameObject e = Instantiate(Resources.Load("Prefabs/Egg") as GameObject); // Prefab MUST BE locaed in Resources/Prefab folder!
                    e.transform.localPosition = transform.localPosition;
                    e.transform.up=transform.up;
                    NewBehaviourScript3.ntime=NewBehaviourScript3.stime=0;
                }               
                //Debug.Log("Spawn Eggs:");
                // mTotalEggCount++;
            }
        }
    }
    private void OnCollisionEnter2D(Collision2D collision)
    {
        if(gameObject.tag=="Hero"&&collision.gameObject.tag=="Plane")
        {
            Destroy(collision.gameObject);
            NewBehaviourScript3.sumplane-=1;
            NewBehaviourScript3.dsum+=1;
            NewBehaviourScript3.tsum+=1;
            //Debug.Log("11111111");
            if(NewBehaviourScript3.sumplane<=9)
            {
               GameObject e = Instantiate(Resources.Load("Prefabs/Plane") as GameObject); // Prefab MUST BE locaed in Resources/Prefab folder!
	           Vector3 h=e.transform.localPosition;
               h.x=UnityEngine.Random.Range(-90,90);
               h.y=UnityEngine.Random.Range(-90,90);
               e.transform.localPosition=h;
               NewBehaviourScript3.sumplane+=1;
            }
        }    
    }
}