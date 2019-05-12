#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>
#include <windows.h>

using namespace std;

//                               

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
vector<Track> testDB = {{"Adele",                          "19",                          2008,1, "Daydreamer",                  "pop,debut album",                   { 3,40},"England"}
                       ,{"Adele",                          "19",                          2008,10,"My same",                     "pop,debut album",                   { 3,15},"England"}
                       ,{"Adele",                          "19",                          2008,11,"Tired",                       "pop,debut album",                   { 4,18},"England"}
                       ,{"Adele",                          "19",                          2008,12,"Hometown glory",              "pop,debut album",                   { 4,31},"England"}
                       ,{"Adele",                          "19",                          2008,2, "Best for last",               "pop,debut album",                   { 4,18},"England"}
                       ,{"Adele",                          "19",                          2008,3, "Chasing pavements",           "pop,debut album",                   { 3,30},"England"}
                       ,{"Adele",                          "19",                          2008,4, "Cold shoulder",               "pop,debut album",                   { 3,11},"England"}
                       ,{"Adele",                          "19",                          2008,5, "Crazy for you",               "pop,debut album",                   { 3,28},"England"}
                       ,{"Adele",                          "19",                          2008,6, "Melt my heart to stone",      "pop,debut album",                   { 3,23},"England"}
                       ,{"Adele",                          "19",                          2008,7, "First love",                  "pop,debut album",                   { 3,10},"England"}
                       ,{"Adele",                          "19",                          2008,8, "Right as rain",               "pop,debut album",                   { 3,17},"England"}
                       ,{"Adele",                          "19",                          2008,9, "Make you feel my love",       "pop,debut album",                   { 3,32},"England"}
                       ,{"Adele",                          "21",                          2011,1, "Rolling in the deep",         "pop",                               { 3,49},"England"}
                       ,{"Adele",                          "21",                          2011,10,"Lovesong",                    "pop",                               { 5,16},"England"}
                       ,{"Adele",                          "21",                          2011,11,"Someone like you",            "pop",                               { 4,47},"England"}
                       ,{"Adele",                          "21",                          2011,2, "Rumour has it",               "pop",                               { 3,43},"England"}
                       ,{"Adele",                          "21",                          2011,3, "Turning tables",              "pop",                               { 4,10},"England"}
                       ,{"Adele",                          "21",                          2011,4, "Don't you remember",          "pop",                               { 4, 3},"England"}
                       ,{"Adele",                          "21",                          2011,5, "Set fire to the rain",        "pop",                               { 4, 1},"England"}
                       ,{"Adele",                          "21",                          2011,6, "He won't go",                 "pop",                               { 4,37},"England"}
                       ,{"Adele",                          "21",                          2011,7, "Take it all",                 "pop",                               { 3,48},"England"}
                       ,{"Adele",                          "21",                          2011,8, "I'll be waiting",             "pop",                               { 4, 1},"England"}
                       ,{"Adele",                          "21",                          2011,9, "One and only",                "pop",                               { 5,48},"England"}
                       ,{"All them witches",               "Dying surfer meets his maker",2015,1, "Call me star",                "alternative,rock",                  { 3,54},"U.S.A."}
                       ,{"All them witches",               "Dying surfer meets his maker",2015,2, "El centro",                   "alternative,rock,instrumental",     { 8,25},"U.S.A."}
                       ,{"All them witches",               "Dying surfer meets his maker",2015,3, "Dirt preachers",              "alternative,rock",                  { 3,44},"U.S.A."}
                       ,{"All them witches",               "Dying surfer meets his maker",2015,4, "This is where it falls apart","alternative,rock",                  { 7, 2},"U.S.A."}
                       ,{"All them witches",               "Dying surfer meets his maker",2015,5, "Mellowing",                   "alternative,instrumental",          { 3,11},"U.S.A."}
                       ,{"All them witches",               "Dying surfer meets his maker",2015,6, "Open passageways",            "alternative,rock",                  { 3,14},"U.S.A."}
                       ,{"All them witches",               "Dying surfer meets his maker",2015,7, "Instrumental 2 (welcome to the caveman future)"
                                                                                                                                ,"alternative,rock,instrumental",     { 2,33},"U.S.A."}
                       ,{"All them witches",               "Dying surfer meets his maker",2015,8, "Talisman",                    "alternative,rock",                  { 6, 7},"U.S.A."}
                       ,{"All them witches",               "Dying surfer meets his maker",2015,9, "Blood and sand / milk and endless waters","alternative,rock",      { 7,20},"U.S.A."}
                       ,{"The decemberists",               "The tain",                    2005,1, "The tain (parts i-iv)",       "progressive,experimental,folk,rock",{18,35},"U.S.A."}
                       ,{"Colin Stetson and Sarah Neufeld","Never were the way she was",  2015,1, "The sun roars into view",     "jazz,instrumental,experimental",    { 7,37},"U.S.A.,Canada"}
                       ,{"Colin Stetson and Sarah Neufeld","Never were the way she was"  ,2015,2, "Won't be a thing to become",  "jazz,instrumental,experimental",    { 3,24},"U.S.A.,Canada"}
                       ,{"Colin Stetson and Sarah Neufeld","Never were the way she was",  2015,3, "In the vespers",              "jazz,instrumental,experimental",    { 6, 2},"U.S.A.,Canada"}
                       ,{"Colin Stetson and Sarah Neufeld","Never were the way she was",  2015,4, "And still they move",         "jazz,instrumental,experimental",    { 2,56},"U.S.A.,Canada"}
                       ,{"Colin Stetson and Sarah Neufeld","Never were the way she was",  2015,5, "With the dark hug of time",   "jazz,instrumental,experimental",    { 6,34},"U.S.A.,Canada"}
                       ,{"Colin Stetson and Sarah Neufeld","Never were the way she was",  2015,6, "The rest of us",              "jazz,instrumental,experimental",    { 6,30},"U.S.A.,Canada"}
                       ,{"Colin Stetson and Sarah Neufeld","Never were the way she was",  2015,7, "Never were the way she was",  "jazz,instrumental,experimental",    { 8,12},"U.S.A.,Canada"}
                       ,{"Colin Stetson and Sarah Neufeld","Never were the way she was",  2015,8, "Flight",                      "jazz,instrumental,experimental",    { 1,38},"U.S.A.,Canada"}
                       } ;

bool match (string sub, string source)
{//              
    assert (true) ;
/*                
                                                                                  
*/
    return source.find(sub) != string::npos ;
}

ostream& operator<< (ostream& out, const Length length)
{//              
    assert (true) ;
/*                
                                                                                           
*/
    if (length.seconds <10)
    {
        out << length.minutes << ":0" << length.seconds;
        return out;
    }
    out << length.minutes << ':' << length.seconds;
    return out ;
}

istream& operator>> (istream& in, Length& length)
{//              
    assert (true) ;
/*                
                                                                                    
*/
    string s;
    in >> s;
    char i;
    int minutes=0, seconds=0;
    bool min_done=false;
    for (int i=0; i<s.size(); i++)
    {

        if (s[i]-48 > 9)
        {
            min_done=true;
        }
        else if ((s[i]-48 <= 9 && s[i]-48 >= 0) && min_done==false)
        {
            minutes=minutes*10+(s[i]-48);
        }
        else
        {
            seconds=seconds*10+(s[i]-48);
        }
    }
    length.minutes=minutes;
    length.seconds=seconds;
    return in;
}

Length operator+ (const Length& a, const Length& b)
{//              
    assert (0 <= a.minutes && 0 <= a.seconds && a.seconds < 60 && 0 <= b.minutes && 0 <= b.seconds && b.seconds < 60) ;
/*                
                                 
*/
    Length c;
    c.minutes=a.minutes+b.minutes;
    if ((a.seconds+b.seconds)>59)
    {
        c.minutes++;
        c.seconds=(a.seconds+b.seconds-60);
        return c;
    }
    c.seconds=a.seconds+b.seconds;
    return c;
}

void show_track (Track track, TrackDisplay lt)
{//              
    assert (true) ;
/*                
                                                                                         
*/
    if (lt.showArtist==true)
    {
        cout << "Artist name: \t\t" << track.artist << "\n";
    }
    if (lt.showAlbum==true)
    {
        cout << "CD title: \t\t" << track.cd << "\n";
    }
    if (lt.showYear==true)
    {
        cout << "Year of appearance: \t"<< track.year << "\n";
    }
    if (lt.showTrack==true)
    {
        cout << "Track number: \t\t" << track.track << "\n";
    }
    if (lt.showTitle==true)
    {
        cout << "Track title: \t\t" << track.title << "\n";
    }
    if (lt.showTags==true)
    {
        cout << "Track tags: \t\t" << track.tags << "\n";
    }
    if (lt.showLength==true)
    {
        cout << "Track length: \t\t" << track.time << "\n";
    }
    if (lt.showCountry==true)
    {
        cout << "Country: \t\t" << track.country << "\n";
    }
    cout << "\n";
}

int match_tracks (vector<Track>& tracks, string track, bool display)
{
    //               
    assert(true);
    /*                
                                                                                            
                                                                          */
    TrackDisplay a;
    a={true,true,true,true,true,true,true,true};
    int counter=0;
    for (int i=0; i< tracks.size() ; i++)
    {
         if (match (track,tracks[i].title))
         {
             if (display==true)
             {
                 show_track(tracks[i],a);
             }
             counter++;
         }
    }
    return counter;
}

int match_artists (vector<Track>& tracks, string artist, bool display)
{
    //               
    assert(true);
    /*                
                                                                                                                        
                                                                                                            */
    TrackDisplay a;
    a={true, false, false, false, false, false, false, false};
    int counter=0, sum;
    vector<string>done(0);
    //                                                                                                  
    for (int i=0; i< tracks.size() ; i++)
    {
         if (match (artist,tracks[i].artist))
         {
            sum=0;
            for (int j=0; j<done.size();j++)
            {
                sum=sum+(done[j]==tracks[i].artist);
            }
            if (display==true && sum==0)
            {
                done.push_back(tracks[i].artist);
                show_track(tracks[i],a);
                counter++;
            }
         }
    }
    return counter;
}
int match_cds (vector<Track>& tracks, string artist, bool display)
{
    //               
    assert(true);
    /*                
                                                                                                                       
                                                                                  */
    TrackDisplay a;
    a={true, true, true, false, false, false, false, false};
    int counter=0, sum;
    vector<string>done(0);
    for (int i=0; i< tracks.size() ; i++)
    {
         if (match (artist,tracks[i].artist))
         {
            sum=0;
            for (int k=0; k<done.size(); k++)
            {
                sum=sum+(done[k]==tracks[i].cd);
            }
            if (display==true && sum==0)
            {
                done.push_back(tracks[i].cd);
                show_track(tracks[i],a);
                counter++;
            }
         }
    }
    return counter;
}

int number_of_cds (vector<Track>& tracks)
{
    //               
    assert(true);
    /*                
                                                                     */
    vector<string>done(0);
    int sum=0, counter=0;
    for (int i=0; i<tracks.size(); i++)
    {
        sum=0;
        for (int k=0; k<done.size(); k++)
        {
            sum=sum+(done[k]==tracks[i].cd);
        }
        if ( sum==0)
        {
            done.push_back(tracks[i].cd);
            counter++;
        }
    }
    return counter;
}

istream& operator>> (istream& in, Track& track)
{//              
    assert (true) ;
/*                
                                                                                                                 
                                                          
*/
    string a;
    getline(in, track.artist);
    getline(in, track.cd);
    in >> track.year;
    in >> track.track;
    getline(in,track.title);
    getline(in,track.title);
    getline(in, track.tags);
    in >> track.time;
    getline(in,track.country);
    getline(in,track.country);
    getline(in,a);
    return in;
}

int main()
{//              
    assert (true) ;
/*                
                                                                                       
                                                                                        
                                                                                         
                                      
*/
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    Length l1 = {42,42}, l2 = {0,0}, l3 = {3,21}, l4 = {3,14},l5;
    int num_o_tracks=0, num_o_artist=0, num_o_cd, num_o_albums;
    ifstream infile;
    infile.open("Tracks.txt");
    if (!infile.is_open())
    {
        return 3;
    }
    vector <Track> Music_database;
    Track track1;
    TrackDisplay a;
    a={true,true,true,true,true,true,true,true};
    infile >> track1;
    while (!infile.eof())
    {
        Music_database.push_back(track1);
        //                     
        infile >> track1;
    }
    infile.close();
    num_o_tracks=match_tracks(Music_database,"el",true);
    num_o_artist=match_artists(Music_database, "el", true);
    num_o_albums=match_cds(Music_database,"el",true);
    num_o_cd=number_of_cds(Music_database);
    cout << "Number of matching tracks found: " << num_o_tracks << endl;
    cout << "Number of matching artists found: " << num_o_artist << endl;
    cout << "Number of matching albums found: " << num_o_albums << endl;
    cout << "Number of cd's found: " << num_o_cd << endl;
}

