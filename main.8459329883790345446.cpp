#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>

//                                         
using namespace std;
const int MAX_CD_ARTIST=9000;
struct Length
{
	int minutes;							//               
	int seconds;							//                 
};

struct Track
{
	string artist;                          //               
	string cd;                              //         
	int    year;                            //                              
	int    track;							//             
	string title;                           //            
	string tags;                            //     
	Length time;							//             
	string country;                         //                             
};

struct TrackDisplay
{
	bool showArtist;						//                             
	bool showAlbum;							//                       
	bool showYear;							//                                 
	bool showTrack;							//                           
	bool showTitle;							//                          
	bool showTags;                          //                   
	bool showLength;						//                           
	bool showCountry;                       //                                      
};

/*                                                                                 
                                                                                     
*/
/*                                                                                                                                                                                         

                                                                                                                                                                                        
                                                                                                                                                                                        
                                                                                                                                                                                        
                                                                                                                                                                                        
                                                                                                                                                                                        
                                                                                                                                                                                        
                                                                                                                                                                                        
                                                                                                                                                                                        
                                                                                                                                                                                        
                                                                                                                                                                                        
                                                                                                                                                                                        
                                                                                                                                                                                        
                                                                                                                                                                                        
                                                                                                                                                                                        
                                                                                                                                                                                        
                                                                                                                                                                                        
                                                                                                                                                                                        
                                                                                                                                                                                        
                                                                                                                                                                                        
                                                                                                                                                                                        
                                                                                                                                                                                        
                                                                                                                                                                                        
                                                                                                                                                                                        
                                                                                                                                                                                       
                                                                                                                                                                                       
                                                                                                                                                                                       
                                                                                                                                                                                       
                                                                                                                                                                                       
                                                                                                                                                                                       
                                                                                                                                                  
                                                                                                                                                                                       
                                                                                                                                                                                       
                                                                                                                                                                                       
                                                                                                                                                                                       
                                                                                                                                                                                              
                                                                                                                                                                                              
                                                                                                                                                                                              
                                                                                                                                                                                              
                                                                                                                                                                                              
                                                                                                                                                                                              
                                                                                                                                                                                              
                                                                                                                                                                                              
                          
*/
bool match (string sub, string source)
{//              
    assert (true) ;
/*                
                                                                                  
*/
    return source.find(sub) != string::npos ;
}

ostream& operator<< (ostream& out, const Length length)
{//              
    assert (0<=length.seconds && length.seconds<60 && 0<=length.minutes) ;
/*                
                                                                                          
*/
   cout<<length.minutes<<':'<<length.seconds;
}

istream& operator>> (istream& in, Length& length)
{//              
    assert (true) ;
/*                
                                                                                    
*/
    string hold;
    getline(in,hold);
    char seconds[3];//                                                                    
    char minutes[7];//                                                                                 
    int index=0;
    bool go_on=true;
    while (hold[index]!=':' && go_on) //                               
    {
        minutes[index]=hold[index];
        if(index>=6)
        {
            cout<<"this takes to long default to \"00:00\" \n";
            go_on=false;
        }
        index++;
    }
    if (go_on)
    {
        length.minutes=atoi(minutes);
        index++;
        seconds[0]=hold[index];
        index++;
        seconds[1]=hold[index]; //                                                                  
        length.seconds=atoi(seconds);
    }
    else  //       
    {
        length.minutes=0;
        length.seconds=0;
    }
    if (length.seconds>=60)
        cout<<"Warning an incorrect value has been stored!";
}

Length operator+ (const Length& a, const Length& b)
{//              
    assert (0 <= a.minutes && 0 <= a.seconds && a.seconds < 60 && 0 <= b.minutes && 0 <= b.seconds && b.seconds < 60) ;
/*                
                                 
*/
    Length newlength;
    newlength.seconds=(a.seconds+b.seconds)%60; //                                                      
    newlength.minutes=a.minutes+b.minutes+(a.seconds+b.seconds)/60; //                                                                       
    return newlength;
}

void show_track (Track track, TrackDisplay lt)
{//              
    assert (true) ;
/*                
                                                                                         
*/
    bool pass_line=false;
    if (lt.showArtist) //                                 
    {
        cout<<"Artist:"<<track.artist<<" ";
        pass_line=true;
    }
    if (lt.showAlbum)
    {
        cout<<"Album:"<<track.cd<<" ";
        pass_line=true;
    }
    if (lt.showYear)
    {
        cout<<"Year of release:"<<track.year<<" ";
        pass_line=true;
    }
    if (lt.showTrack)
    {
        cout<<"Tracknumber:"<<track.track<<" ";
        pass_line=true;
    }
    if (lt.showTitle)
    {
        cout<<"Trackname:"<<track.title<<" ";
        pass_line=true;
    }
    if (lt.showTags)
    {
        cout<<"Tags:"<<track.tags<<" ";
        pass_line=true;
    }
    if (lt.showLength)
    {
        cout<<"Duration:"<<track.time<<" ";
        pass_line=true;
    }
    if (lt.showCountry)
    {
        cout<<"Country of release:"<<track.country;
        pass_line=true;
    }
    if(pass_line)
        cout<<".\n"; //                                     
}
int match_tracks (vector<Track>& tracks, string track, bool display)
{
    assert(true);
    TrackDisplay show_all={true,true,true,true,true,true,true,true};//                                                              
    int tracks_to_check=tracks.size();
    int matches=0;
    for (int index=0; index<tracks_to_check; index++) //                            
    {
        if (match(track, tracks.at(index).title))  //                 
        {
            if(display)
                show_track(tracks.at(index),show_all); //                 
            matches++; //                           
        }
    }
    cout<<"Total tracks found:"<<matches<<".\n";
    return matches;
}
int match_artists (vector<Track>& tracks, string artist, bool display)
{
    assert(true);
    TrackDisplay show_all={true,false,false,false,false,false,false,false};//                         
    int tracks_to_check=tracks.size();
    int matches=0;
    string namelist[MAX_CD_ARTIST]; //                           
    for (int index=0; index<tracks_to_check; index++) //                    
    {
        if (match(artist, tracks.at(index).artist))
        {
            bool not_in_list=true; //                 
            for (int start=0; start<matches; start++) //          
            {
                if (namelist[start]==tracks.at(index).artist) //                           
                    not_in_list=false; //                           
            }
            if (not_in_list) //                        
            {
                namelist[matches]=tracks.at(index).artist; //                 
                matches++; //                
                if (display) //                 
                    show_track(tracks.at(index),show_all);
                if (matches==MAX_CD_ARTIST) //                                                                                                                                                         
                {
                    cout<<"The total number of artists matching name requirements is "<<matches<<" or more, which is the maximum allowed. \n";
                    return MAX_CD_ARTIST; //                  
                }
            }

        }
    }
    cout<<"Total number of artists matching name requirements found is:"<<matches<<".\n";
    return matches;
}
int match_cds (vector<Track>& tracks, string artist, bool display)//                                                
{
    assert(true);
    TrackDisplay show_all={true,true,true,false,false,false,false,false};//                      
    int tracks_to_check=tracks.size();
    int matches=0;
    string cdlist[MAX_CD_ARTIST];
    for (int index=0; index<tracks_to_check; index++)
    {
        if (match(artist, tracks.at(index).artist))
        {
            bool not_in_list=true;
            for (int start=0; start<matches; start++)
            {
                if (cdlist[start]==tracks.at(index).cd)
                    not_in_list=false;
            }
            if (not_in_list)
            {
                cdlist[matches]=tracks.at(index).cd;
                matches++;
                if (display)
                    show_track(tracks.at(index),show_all);
                if (matches==MAX_CD_ARTIST)
                {
                    cout<<"The total number of cds  matching artist requirements is "<<matches<<" or more, which is the maximum allowed. \n";
                    return MAX_CD_ARTIST;
                }
            }

        }
    }
    cout<<"Total number of cds matching artist requirements found is:"<<matches<<".\n";
    return matches;
}
int number_of_cds (vector<Track>& tracks)
{
    assert(true);
    int tracks_to_check=tracks.size();
    int matches=0;
    string cdlist[MAX_CD_ARTIST];//               
    for (int index=0; index<tracks_to_check; index++)
    {
        bool not_in_list=true; //                     
        for (int start=0; start<matches; start++)
        {
            if (cdlist[start]==(tracks.at(index)).cd)
                not_in_list=false;
        }
        if (not_in_list) //      
        {
            cdlist[matches]=(tracks.at(index)).cd;//                           
            matches++;
            cout<<matches;
            if (matches==MAX_CD_ARTIST) //                                                                              
            {
                cout<<"The total number of unique cds on tracklist is"<<matches<<"or more, which is the maximum allowed. \n";
                return MAX_CD_ARTIST;
            }
        }
    }
    cout<<"The total number of unique cds on tracklist is:"<<matches<<".\n";
    return matches;
}
istream& operator>> (istream& in, Track& track) //                                                                                                      
{//              
    assert (true) ;//                                     
/*                
                                                                                                                 
                                                          
*/
    string safetycheck; //                                                          
    getline(in,safetycheck); //                   
    bool safe=true; //                                                         
    if (safetycheck=="") //                            
        safe=false; //                  
        in.fail();  //                          
    if (safe)
    {
        track.artist=safetycheck; //                                                             
        getline(in,track.cd);
        char year[5];
        in.getline(year,5);
        track.year=atoi(year);
        char tracknumber[4];
        in.getline(tracknumber,4);
        track.track=atoi(tracknumber);
        getline(in,track.title);
        getline(in,track.tags);
        in>>track.time;
        getline(in,track.country);
        in.get();//                                        

    }
}

int main()
{//              
    assert (true) ;
/*                
                                                                                       
                                                                                        
                                                                                         
                                      
*/
    TrackDisplay show_all={true,true,true,true,true,true,true,true};
    ifstream infile;
    vector<Track> filledtracks;
    Track nexttrack;
    infile.open("Tracks.txt");
    while(infile)
    {
        infile>>nexttrack;
        filledtracks.push_back(nexttrack);
        show_track(nexttrack,show_all);
    }
    infile.clear();
    infile.close();
	return 0;
}

