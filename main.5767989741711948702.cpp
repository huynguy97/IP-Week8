//                         
//                       

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

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
out << length.minutes << ":" << length.seconds;
 return out;
}

istream& operator>> (istream& in, Length& length)
{//              
    assert (true) ;
/*                
                                                                                    
*/
in >> length.minutes >> length.seconds;
return in;

}

Length operator+ (const Length& a, const Length& b)
{//              
    assert (0 <= a.minutes && 0 <= a.seconds && a.seconds < 60 && 0 <= b.minutes && 0 <= b.seconds && b.seconds < 60) ;
/*                
                                 
*/
    Length sum;
    sum.minutes = a.minutes + b.minutes;
    sum.seconds = a.seconds + b.seconds;

    while (sum.seconds > 59)
    {
        sum.seconds = sum.seconds - 60;
        sum.minutes++;
    }
    if (sum.seconds < 10)
        cout << "the combined time of the songs is       :" << sum.minutes << ":" << "0" << sum.seconds << endl << endl;
    else
    cout << "the combined time of the songs is      :" << sum << endl << endl;
}

void show_track (Track track, TrackDisplay lt)
{//              
    assert (true) ;
/*                
                                                                                         
*/
if (lt.showArtist) cout <<  "The artist of the song is               :" << track.artist << endl;
if (lt.showAlbum) cout <<   "The album is called                     :" << track.cd<< endl;
if (lt.showYear) cout <<    "The song was made in the year           :" << track.year<< endl;
if (lt.showTrack) cout <<   "The track number is                     :" << track.track<< endl;
if (lt.showTitle) cout <<   "The title of the track is               :" << track.title<< endl;
if (lt.showTags) cout <<    "tag of the track is                     :" <<track.tags<< endl;
if (lt.showLength) cout <<  "the duration of the song                :" <<track.time<< endl;
if (lt.showCountry) cout << "the country of where the track was made :" <<track.country<< endl;
}

istream& operator>> (istream& in, Track& track)
{//              
    assert (true) ;
/*                
                                                                                                                 
                                                          
*/

}

int match_tracks (vector<Track>& tracks, string tracke, bool display)
{
    if (display)
    {
 TrackDisplay lt = {true,true,true,true,true,true,true,true};
    cout << "give title: ";
        string a;
    cin >> a;
    int counts;
  for (int t = 0; t<tracks.size() ; t++)
    {if (match (a, tracks[t].title))
        {
        show_track(testDB[t],lt);
        cout << endl;
        counts++;
        }
    }
    }
}

int match_artists (vector<Track>& tracks, string artist, bool display)
{
 if(display)
 {
 TrackDisplay lt = {true,true,true,true,true,true,true,true};
    cout << "give artist: ";
        string b;
    cin >> b;
    int t;
    string f = "blauwblauwblauwblauw";
    int counts;
  for (t = 0; t<tracks.size() ; t++)
    {if (match (b, tracks[t].artist)&&tracks[t].artist!=f)
        {
        show_track(testDB[t],lt);
        cout << endl;
        counts++;
        f = tracks[t].artist;
        }
    }
 }
}

int match_cds (vector<Track>& tracks, string artist, bool display)
{
 if(display)
 {
 TrackDisplay lt = {true,true,true,false,false,false,false,false};
    cout << "give artist: ";
        string b;
    cin >> b;
    int t;
    string f = "blauwblauwblauwblauw";
    int counts;
  for (t = 0; t<tracks.size() ; t++)
    {if (match (b, tracks[t].artist)&&tracks[t].cd!=f)
        {
        show_track(testDB[t],lt);
        cout << endl;
        counts++;
        f = tracks[t].cd;
        }
    }
 }
}

int number_of_cds (vector<Track>& tracks)
{
    string b;
    int t;
    string f = "blauwblauwblauwblauw";
    int counts;
  for (t = 0; t<tracks.size() ; t++)
    {if (match (b, tracks[t].artist)&&tracks[t].cd!=f)
        {
        f = tracks[t].cd;
        counts = counts +1;
        }
        cout << counts;
    }
}

int main()
{//              
    assert (true) ;
/*                
                                                                                       
                                                                                        
                                                                                         
                                      
*/
 Length d = {42,42};
 Length b = {3,21};
 Length c = d+b;

/*               
                             
                                                            
                       
*/
bool display = true;
vector<Track> tracks = testDB;
string tracke;
string artist;

match_tracks (tracks,tracke,display);

match_artists (tracks,artist,display);

match_cds (tracks, artist, display);

number_of_cds ( tracks);
}

//                                   
//            

