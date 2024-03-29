//  Link: https://www.codewithharry.com/videos/cpp-tutorials-in-hindi-57/

#include<iostream>
#include<string.h>

using namespace std;

class CWH{
    protected:
        string title;
        float rating;
    public:
        CWH(){}
        CWH(string title, float rating){
            this->title = title;
            this->rating = rating;
        }
        virtual void display(){ // Can also be written as: void virtual display
            cout<<"Sad";
        }
};

class CWHVideo: public CWH{
    int videoLength;
    public:
        CWHVideo(string title, float rating, int videoLength):CWH(title, rating){          
            this->videoLength = videoLength;
        }
        void display(){
            cout<<"This is an amazing video with title "<<title<<endl;
            cout<<"Ratings: "<<rating<<" out of 5 stars"<<endl;
            cout<<"Length of this video is: "<<videoLength<<" minutes"<<endl;
        }
        
};

class CWHText: public CWH{
    int wordCount;
    public:
        CWHText(string title, float rating, int wordCount):CWH(title, rating){          
            this->wordCount = wordCount;
        }
        void display(){
            cout<<"This is an amazing text tutorial with title "<<title<<endl;
            cout<<"Ratings of this text tutorial: "<<rating<<" out of 5 stars"<<endl;
            cout<<"No of words in this text tutorial is: "<<wordCount<<" words"<<endl;
        }
        
};




int main(){
    // For Video:
    string videoTitle = "C++ Tutorial";
    float videoRating = 4.5;
    int videoLength = 27;

    CWHVideo cpp_video_tutorial(videoTitle, videoRating, videoLength);
    // cpp_video_tutorial.display();

    // For Text:
    string textTitle = "C++ Tutorial";
    float textRating = 4.2;
    int wordCount = 500;

    CWHText cpp_text_tutorial(textTitle, textRating, wordCount);
    // cpp_text_tutorial.display();

    CWH *tuts[2]; // Array of Pointers

    tuts[0] = &cpp_video_tutorial;
    tuts[1] = &cpp_text_tutorial;
    
    tuts[0]->display();
    tuts[1]->display();
    // If we did'nt use Virtual Function in class CWH, thn by default, early binding would have taken place and the display function of class CWH would have been called.
    // But we have used the “virtual” keyword with the “display” function of the base class to make is a virtual function so when the display function is called by using the base class pointer the display function of the derived class will run because the base class pointer is pointing to the derived class object.

    return 0;
}
/*
Rules for virtual functions
1. They cannot be static.
2. They are accessed by object pointers.
3. Virtual functions can be a friend of another class.
4. A virtual function in the base class might not be used.
5. If a virtual function is defined in a base class, there is no necessity of redefining it in the derived class.
*/