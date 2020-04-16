/*
	debug:
	Chinese change to Engilsh;
	
	while(starx > 3){			stary = starx % 4;
               starx -= 4;	change to =>	starx = starx / 4; 
                stary++;
            }
	
*/
#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
int mapp[4][4]={{0, 0, 0, 0 },
                {0, 0, 0, 0 },
                {0, 0, 0, 0 },
                {0, 0, 0, 0 }};
int next[4][2]={{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int i, j, starx, stary, check = 2, temp, x, y, dou, ii, z, fomap[8], point = 0, times = 1, a;
void ran(int cou){
	times++;
     for( i=0; i<cou; i++){
        do{
        	stary=0;
            	srand(time(0) + j);
            	starx= rand() % 16;
            	stary = starx % 4;
		starx = starx / 4; 
            	j++;
        }while( mapp[stary][starx] != 0);
        a = rand() % times;
        if( starx <= 10)
        	mapp[stary][starx] = 2;
        else
        	mapp[stary][starx] = 4;
    }
}
 void co( int a, int b, int c, int d, int x, int y,int dir){
	for( i=4; i<8; i++)
		fomap[i] = 0;
	fomap[0] = a;
	fomap[1] = b;
	fomap[2] = c;
	fomap[3] = d;
	ii= 0;
	for( i=0; i<4; i++){
		if( fomap[i] != 0 ){
			temp = fomap[i];
			fomap[i] = 0;
			fomap[ii] = temp;
			ii++;
		}
	}
	cout<<endl;
	for( i=0; i<ii; i++){
		if( fomap[i] == fomap[i + 1]){
			fomap[i]*= 2;
			point += fomap[i];
			fomap[i + 1]= -1;
			i += 1;
		}
	}
	ii = 0;
	for( i= 0; i<8; i++){
		if( fomap[i] != -1){
			mapp[x][y] = fomap[i];
			ii++;
			x += next[dir][1];
			y += next[dir][0];
		}
		if( ii == 4)
			break;
	}	
}
int main()
{
    int dir;
    ran (2);
    do{
        if( check == -1)
            ran (1);
        for( i=0; i<4; i++){
        	for( j=0; j<4; j++){
            	cout.width(5);
           		cout<<mapp[i][j];
            }
            cout<<endl<<endl<<endl;
        }    
        dir = getch();
        switch(dir){
            case 224:
                dir = getch();
                switch(dir){
                    case 75:    
			for( int i= 0; i<4; i++){
				ii = 3;
				co( mapp[i][ii - 3], mapp[i][ii - 2], mapp[i][ii - 1], mapp[i][ii], i, 0, 0);
			}
                        break;
                    case 77:     
			for( int i=0; i<4; i++){
				ii = 3;
				co( mapp[i][ii], mapp[i][ii - 1], mapp[i][ii - 2], mapp[i][ii - 3], i, 3, 2);
			}
                        break;
                    case 72:    
			for( int i=0; i<4; i++){
				ii = 3;
				co( mapp[ii - 3][i], mapp[ii - 2][i], mapp[ii - 1][i], mapp[ii][i], 0, i, 1);
			}
                        break;
                    case 80:    
			for( int i=0; i<4; i++){
				ii = 3;
				co( mapp[ii][i], mapp[ii - 1][i], mapp[ii - 2][i], mapp[ii - 3][i], 3, i, 3 );
			}
                        break;
                }
    	}
		check = 0;
    	for( i=0; i<4; i++){
    		for( j=0; j<4; j++){
    			if( mapp[i][j] == 0 ){
    				j+=4;
    				i+=4;
    				check = -1;
    				break;
				}
			}
		}
		if( check == 0 ){
			for( i=0; i<4; i++){
    			for( j=0; j<4; j++){
    				for( z=0; z<2; z++){
    					x = j + next[z][1];
						y = i + next[z][0];
						if( x == 4 || y == 4)
							continue;
						if( mapp[x][y] == 0 || mapp[x][y] == mapp[j][i]){
							check ++;
							z += 2;
							j += 3;
							i += 3;
							break;		
						}
					}
				}
			}
		}
		system("cls");
    }while( check != 0);	
     for( i=0; i<4; i++){
        	for( j=0; j<4; j++){
            	cout.width(5);
           		cout<<mapp[i][j];
            }
            cout<<endl<<endl<<endl;
        }    
    cout<<" the END "<<endl<<"Your score "<< point;
    return 0;
}
