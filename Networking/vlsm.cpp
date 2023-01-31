#include<bits/stdc++.h>
using namespace std;
 
void submask(int i, int *a, int *b){
 
        *a = 0;
        *b = 0;
        int k =  ceil(log2(i));
        int j = 32 - 16 - k;
        if(j>8){
            *a = 255;
            j -= 8;
            for(int i=7;i>=(8-j);i--)
                *b += pow(2,i);
        }
        else if(j<8){
            for(int i=7;i>=(8-j);i--)
                *a += pow(2,i);
            *b = 0;
        }
        else if(j==8){
            *a = 255;
            *b = 0;
        }
    }
 
int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cout << "Enter network address with mask: ";
    int sub;
    int abcd[4];
    string net;
    cin >> net;
    int n=0;
    string temp;
    for(int i=0;i<=int(net.size());i++){
        if(net[i]!='.' && net[i]!='/'){
                temp += net[i];
        }
        else if(net[i]=='.'){
            stringstream rand(temp);
            rand >> abcd[n];
            temp.clear();
            n++;
        }
        else if(net[i]=='/'){
            stringstream rand2(temp);
            rand2 >> abcd[n];
            temp.clear();
            temp += net[i+1];
            temp += net[i+2];
            stringstream rand(temp);
            rand >> sub;
            break;
        }
    }
 
    cout << endl;
    cout << "Enter number of host addresses: ";
    n=0;
    cin >> n;
    int hostadd[n];
    for(int i=0;i<n;i++){
        cout << endl <<  "Enter host number:";
        int a;
        cin >> a;
        hostadd[i]=pow(2,ceil(log2(a+2)))-1;
    }
 
    int sum = 0 ;
    for(int i=0;i<n;i++)
        sum += hostadd[i];
 
    int m = pow(2,(32-sub));
    if(sum>m){
        cout << endl << endl << "VLSM is not possible!! Too many hosts for the network." << endl;
        return 0;
        }
    sort(hostadd, hostadd + n, greater<int>());
 
    int arr[n][7];
    int tmp;
    if(hostadd[0]>=256){
            tmp = hostadd[0];
            arr[0][0]= abcd[2];
            arr[0][1]= abcd[3];
            arr[0][2]= arr[0][0]+ floor(hostadd[0]/256);
            arr[0][3]= arr[0][1]+ tmp%256;
            arr[0][6] = 32 - log2(tmp+1);
            submask(hostadd[0],&arr[0][4],&arr[0][5]);
    }
 
    else if(hostadd[0]<256){
            tmp = hostadd[0];
            arr[0][0]= abcd[2];
            arr[0][1]= abcd[3];
            arr[0][2]= arr[0][0];
            arr[0][3]= arr[0][1]+ tmp;
            arr[0][6] = 32 - log2(tmp+1);
            submask(hostadd[0],&arr[0][4],&arr[0][5]);
    }
 
    for(int i=1;i<n;i++){
        tmp = hostadd[i];
            arr[i][0]= (arr[i-1][2]);
            arr[i][1]= (arr[i-1][3])+1;
            if(arr[i][1]==256){
                arr[i][1]=0;
                arr[i][0]+=1;
            }
 
        if(hostadd[i]>=256){
            arr[i][2]= arr[i][0]+ floor(hostadd[0]/256);
            arr[i][3]= arr[i][1]+ tmp%256;
            arr[i][6] = 32 - log2(tmp+1);
            submask(hostadd[i],&arr[i][4],&arr[i][5]);
            }
 
        else if(hostadd[i]<256){
            arr[i][2]= arr[i][0];
            arr[i][3]= arr[i][1]+ tmp;
            arr[i][6] = 32 - log2(tmp+1);
            submask(hostadd[i],&arr[i][4],&arr[i][5]);
            }
    }
 
    cout << endl << endl;
    cout << "     Network Address  " << "\tBroadcast Address  " << "\tSubnet Mask  ";
 
    for(int i=0;i<n;i++){
    cout << endl << endl;
    cout << i+1 << ".   ";
    cout << abcd[0] << '.'<< abcd[1] << '.' << arr[i][0] << '.'<< arr[i][1] << "/" << arr[i][6] ;
    cout << "\t";
    cout << abcd[0] << '.'<< abcd[1] << '.' << arr[i][2] << '.'<< arr[i][3] << "/" << arr[i][6] ;
    cout << "\t" << "255.255." << arr[i][4] << "." << arr[i][5] ;
    }
    cout << endl << endl;
}