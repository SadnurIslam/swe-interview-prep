/*
Daily practice problem
Link: https://leetcode.com/problems/walking-robot-simulation-ii/?envType=daily-question&envId=2026-04-07
*/

/*
strategy:
1. we will keep track of the current direction of the robot and its current position.
2. we will also keep track of the left turn for each direction in a map.
3. for each step, we will first check how many times it possible to complete a full cycle of the robot's movement (which is 2*(h+w-2)) and reduce the number of steps accordingly. This is because after completing a full cycle, the robot will be back to its original position and direction.
4. then we will move the robot in the current direction until we either run out of steps or hit a wall. If we hit a wall, we will turn left and continue moving until we run out of steps.
N.B. though the initial face in (0,0) is east but after completing a full cycle from (0,0), the robot will be facing south. So we need to update the direction accordingly after reducing the steps by the number of full cycles.
*/




class Robot {
public:
    string dir;
    int x = 0, y;
    map<string,string>left;
    int w,h;
    Robot(int width, int height) {
        left["North"] = "West";
        left["West"] = "South";
        left["South"] = "East";
        left["East"] = "North";
        dir = "East";
        x=0,y=0;
        w=width,h=height;
    }
    
    void step(int num) {
        int sum = 2*(h+w-2);
        int div = num/sum;
        if(div>0){
            num-=div*sum;
            if(x==0 && y==0)dir="South";
        }
        while(num>0){
            if(dir == "East"){
                if(x+num>w-1){
                    num-=w-1-x;
                    x = w-1;
                    dir=left[dir];
                }
                else{
                    x+=num;
                    num=0;
                }
            }
            else if(dir == "North"){
                if(y+num>h-1){
                    num-=h-1-y;
                    y = h-1;
                    dir=left[dir];
                }
                else{
                    y+=num;
                    num=0;
                }
            }
            else if(dir == "West"){
                if(x-num<0){
                    num-=x;
                    x = 0;
                    dir=left[dir];
                }
                else{
                    x-=num;
                    num=0;
                }
            }
            else{
                if(y-num<0){
                    num-=y;
                    y=0;
                    dir=left[dir];
                }
                else{
                    y-=num;
                    num=0;
                }
            }
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        return dir;
    }
};

