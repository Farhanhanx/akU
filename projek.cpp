#include <iostream>
using namespace std;

#define max 5
string data[max];
int top=0;

bool penuh(){
    if(top>=max){
        return true;
    }else{
        return false;
    }
}

bool kosong(){
    if(top==0){
        return true;
    }else{
        return false;
    }
}

void view(){
    if(!kosong()){
        cout<<"Data antrian:"<<endl;
        for(int i=top-1; i>=0; i--){
            cout<<i+1<<". "<<data[i]<<endl;
        }
    }else{
        cout<<"Antrian kosong!!"<<endl;
    }
    if(penuh()){
        cout<<"Antrian penuh!!"<<endl;
    }
    cout<<endl;
}

void enqueue(){
    if(!penuh()){
        cout<<"Masukkan nama antrian:";
        cin>>data[top];
        top++;
    }


}

void dequeue(){
    if(!kosong()){
        for(int i=0; i<top-1; i++){
            data[i]= data[i+1];
        }
        top--;
    }
}
int main(){
    int pil;
   
    do{
        
        cout<<"=====================\n";
        cout<<"     Menu:\n";
        cout<<"1. Enqueue\n";
        cout<<"2. Dequeue\n";
        cout<<"3. Keluar\n";
        cout<<"=====================\n";
        cout<<"Masukkan pilihan:";
        cin>>pil;

        if(pil==1){
            
            enqueue();


        }else if(pil==2){
            
            dequeue();
           
            
        }else if(pil==3){
            cout<<"Terimakasih!! hati hati dijalan"<<endl;
        }else{
            cout<<"Pilihan tidak valid!"<<endl;
        }
        view();
    }while(pil !=3);

    
    
     return 0;
}