#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

#define NORMAL 0
#define STRIKE 1
#define SPARE 2

using namespace std;

int main(){
   // freopen("584.in","r",stdin);

    string buf;

    while(true){
        getline(::cin,buf);
        if(buf == "Game Over")  break;

	    int roll_res[24] = {0};
	    int roll_type[24] = {0};
	    int current_frame[24] = {0};

        bool first = true;
        int index = 0;
        int frame_i = 0;

        for(int i=0;i<buf.length() ;i+=2){
            if(buf[i] >= '0' && buf[i] <= '9'){
                roll_res[index] = buf[i] - '0';
                roll_type[index] = NORMAL;

                current_frame[index] = frame_i;
                if(first){
                    first = false;
                } else{
                    first = true;
                    frame_i++;
                }

                index++;
            } else if(buf[i] == 'X'){
                roll_res[index] = 10;
                roll_type[index]= STRIKE;
                current_frame[index] = frame_i++;
                first = true;

                index++;
            } else if(buf[i] == '/'){
                roll_res[index] = 10 - roll_res[index - 1];
                roll_type[index] = SPARE;
                current_frame[index] = frame_i++;
                first = true;

                index++;
            }
        }

        // for testing
        /*
        cout << "testing: " << endl;
        for(int i=0;i<index;i++){
            cout << i << " --- roll res: " << roll_res[i] << ", frame_num: " << current_frame[i] << ", roll type: " << roll_type[i] << endl;
        }*/


        int sum = 0;
        for(int i=0;i<index && current_frame[i] < 10;i++){

            sum += roll_res[i];

            if(roll_type[i] == STRIKE && current_frame[i] < 10){
                sum += roll_res[i+1];
                sum += roll_res[i+2];
            } else if(roll_type[i] == SPARE && current_frame[i] < 10){
                sum += roll_res[i+1];
            }
        }

        cout << sum << endl;
    }


    return 0;
}

