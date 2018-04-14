//
//  main.cpp
//  testtesttest
//
//  Created by Tapan Lathiya on 11/03/18.
//  Copyright © 2018 Tapan Lathiya. All rights reserved.
//
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include<iostream>
#include <fstream>
#include <istream>
#include<unistd.h>
#include<stdlib.h>
#include <dirent.h>



using namespace std;


string cwd;










bool directory_exists(const char* path)
{
    DIR *d;
    d=opendir(path);
    if(d==NULL) {
        return 0;
    }
    
    else {
        return 1;
    }
        
    

}

void cd_change(string str) {
    //if path has a "/" problem then its because of this............. don't forget noob;
    cwd.append("/" + str);
    
    
}


string get_pwd() {
    char *path=NULL;
    size_t size;
    path=getcwd(path,size);
    string str = path;
    return str;
}

int size_of_file(string str) {
    long begin, end;
    ifstream myfile (str);
    begin = myfile.tellg();
    myfile.seekg (0, ios::end);
    end = myfile.tellg();
    myfile.close();
    return (end-begin);
}

void write_cwd_file(string str) {
    ofstream file;
    file.open("config.txt");
    file<<str;
    file.close();
    
}


void set_cwd() {
    
    int x;
    x=size_of_file("config.txt");
    
    if(x!=0) {
        string STRING;
        ifstream infile;
        infile.open ("config.txt");
        while(!infile.eof())
        {
            getline(infile,STRING);
          
        }
        infile.close();
        cout<<"\nLoading previous working path form file...\n ";
        cout<<STRING<<endl;
        cwd=STRING;
       
    }
    else {
        cwd = get_pwd();
        cout<<cwd<<endl;
    }
    
    
    
    
}

//Process section.


void init_proc() {
    
    int x;
    x=size_of_file("process.txt");
    
    if(x!=0) {
        string STRING;
        ifstream infile;
        infile.open ("process.txt");
        while(!infile.eof())
        {
            getline(infile,STRING);
            
        }
        infile.close();
        cout<<"\nLoading previous working path form file...\n ";
        cout<<STRING<<endl;
        cwd=STRING;
        
    }
    else {
        cwd = get_pwd();
        cout<<cwd<<endl;
    }
    
    
    
    
    
}










//End of Process section.





int main(){
    
    set_cwd();
    string temp;
    string str;
    
    
    
    
    while(true) {
          cout<<endl;
        cin>>str;
        temp="";
      
        for(int i=0;i<2 ;i++) {
            temp = temp+str.at(i);
        }
        
        if(strcmp(temp.c_str(), "cd")==0) {
            
            
            
            temp="";
            
            for(int i=2;i<4;i++) {
                temp = temp + str.at(i);
            }
            if(strcmp(temp.c_str(), "..")==0) {
                cout<<"in ..";
                
                
                if(cwd.length()>0) {
                    
                    int pos=cwd.length()-1;
                    string trim_path="";
                    bool flag=false;
                    while(true) {
                        
                        if(cwd.at(pos)=='/') {
                            if(flag==false) {
                                flag=true;
                                pos--;
                                continue;
                            }
                            for(int i=0;i<=pos;i++) {
                                trim_path=trim_path+cwd.at(i);
                            }
                            cout<<endl<<trim_path<<endl;
                            cwd=trim_path;
                            write_cwd_file(cwd);
                            break;
                        }
                        
                        else {
                            pos--;
                        }
                        if(pos==0) {
                            break;
                            
                        }
                        
                        
                        
                    }
                    
                }
                
                else {
                    cwd="/";
                    
                }
            
                
                
                
                
                
                
            }
            
            else {
                temp="";
                for(int i=2;i<str.length();i++){
                temp = temp + str.at(i);
                
            }
                cout<<endl<<temp<<endl;
            string pathname = cwd+"/"+temp;
            bool h = directory_exists(pathname.c_str());
                cout<<endl<<h<<endl;
                cout<<endl<<pathname<<endl;
            
            if(h==1) {
                cwd=pathname+"/";
                write_cwd_file(cwd);
                }
            else {
                cout<<"\nPath doesn't exist...";
            }
        
            }
        }
            if(strcmp(str.c_str(),"cwd")==0) {
                cout<<cwd<<endl;
            
        }
        if(strcmp(str.c_str(),"ls")==0) {
            string s = "cd "+cwd+" && ls";
            
            system(s.c_str());
        }
        if(strcmp(str.c_str(),"resetcwd")==0) {
            cout<<get_pwd()<<endl;
            string s=get_pwd();
            string sd = "cd " + s + " && "+"rm config.txt";
            system(sd.c_str());
        }
        if(strcmp(str.c_str(),"setcwd")==0) {
            write_cwd_file(get_pwd());
        }
        
        
        if(strcmp(str.c_str(),"proc")==0) {
           
            
            
            
            
        }
        
        
    
    }
}
