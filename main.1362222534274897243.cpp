#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

//                      
//                   
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
    string minString = "";
    string secString = "";
    if(length.minutes < 10) {
       minString = "0";
    }
    if(length.seconds < 10) {
        secString = "0";
    }
    out << minString << length.minutes << ':' << secString << length.seconds;
    return out;
}

istream& operator>> (istream& in, Length& length)
{//              
    assert (true) ;
/*                
                                                                                    
*/
    in >> length.minutes;
    in.ignore();
    in >> length.seconds;
    return in;
}

Length operator+ (const Length& a, const Length& b)
{//              
    assert (0 <= a.minutes && 0 <= a.seconds && a.seconds < 60 && 0 <= b.minutes && 0 <= b.seconds && b.seconds < 60) ;
/*                
                                 
*/
    Length length;
    length.minutes = (a.minutes + b.minutes) + (a.seconds + b.seconds) / 60;
    length.seconds = (a.seconds + b.seconds) % 60;
    return length;
}

void show_track (Track track, TrackDisplay lt)
{//              
    assert (true) ;
/*                
                                                                                         
*/
    if(lt.showArtist)
        cout << "Artist:\t\t" << track.artist << endl;
    if(lt.showAlbum)
        cout << "Album:\t\t" << track.cd << endl;
    if(lt.showYear)
        cout << "Year:\t\t" << track.year << endl;
    if(lt.showTrack)
        cout << "Track:\t\t" << track.track << endl;
    if(lt.showTitle)
        cout << "Title:\t\t" << track.title << endl;
    if(lt.showTags)
        cout << "Tags:\t\t" << track.tags << endl;
    if(lt.showLength)
        cout << "Length:\t\t" << track.time << endl;
    if(lt.showCountry)
        cout << "Country:\t" << track.country << endl;
}

istream& operator>> (istream& in, Track& track)
{//              
    assert (true) ;
/*                
                                                                                                                 
                                                          
*/
    getline(in, track.artist);
    getline(in, track.cd);
    in >> track.year;
    in.ignore();
    in >> track.track;
    in.ignore();
    getline(in, track.title);
    getline(in, track.tags);
    in >> track.time;
    in.ignore();
    getline(in, track.country);

    //                       
    in.ignore();
    return in;
}

int match_tracks (vector<Track>& tracks, string track, bool display) {
    //              
    assert(true);
    //               
    //                                                                                                           
    //                                                
    Track el;
    int counter = 0;
    for(int i = 0; i < tracks.size(); i++) {
        el = tracks[i]; //              
        if(match(track, el.title)) {
            if(display) {
                show_track(el, {1,1,1,1,1,1,1,1});
                cout << endl;
            }
            counter++;
        }
    }
    return counter;
}

int match_artists (vector<Track>& tracks, string artist, bool display){
    //              
    assert(true);
    //               
    //                                                                                                                           
    //                                                
    Track el;
    vector<string> artists;
    int counter = 0;
    for(int i = 0; i < tracks.size(); i++) {
        el = tracks[i]; //              
        if(match(artist, el.artist)) {
            int j = 0;
            bool not_found = true;
            while (j < artists.size() && not_found) {
                if (match(el.artist, artists[j]))
                    not_found = false;
                j++;
            }
            if (not_found){
                if(display)
                    show_track(el, {1,0,0,0,0,0,0,0});
                counter++;
                artists.push_back(el.artist);
            }
        }
    }
    return counter;
}

int match_cds (vector<Track>& tracks, string artist, bool display){
    //              
    assert(true);
    //               
    //                                                                                                                  
    //                                             
    Track el;
    vector<string> cds;
    int counter = 0;
    for(int i = 0; i < tracks.size(); i++) {
        el = tracks[i]; //              
        if(match(artist, el.artist)) {
            int j = 0;
            bool not_found = true;
            while (j < cds.size() && not_found) {
                if (match(el.cd, cds[j]))
                    not_found = false;
                j++;
            }
            if (not_found){
                if(display) {
                    show_track(el, {1,1,1,0,0,0,0,0});
                    cout << endl;
                }
                counter++;
                cds.push_back(el.cd);
            }
        }
    }
    return counter;
}

int number_of_cds (vector<Track>& tracks) {
    //              
    assert(true);
    //               
    //                                    
    Track el;
    vector<string> cds;
    int counter = 0;
    for(int i = 0; i < tracks.size(); i++) {
        el = tracks[i]; //              
        int j = 0;
        bool not_found = true;
        while (j < cds.size() && not_found) {
            if (match(el.cd, cds[j]))
                not_found = false;
            j++;
        }
        if (not_found) {
            counter++;
            cds.push_back(el.cd);
        }
    }
    return counter;
}

int read_file(vector<Track>& tracks, string filename) {
    //              
    assert(true);
    //               
    //                                                                                               
    ifstream file;
    file.open(filename.c_str());
    //                                                
    Track t;
    while(file) {
        file >> t;
        if(file){
            tracks.push_back(t);
        }
    }
    return tracks.size();
}

int main()
{//              
    assert (true) ;
/*                
                                                                                       
                                                                                        
                                                                                         
                                      
*/
    vector<Track> tracks;
    cout << read_file(tracks, "Tracks.txt") << endl;
    string to_find = "el";
    match_tracks(tracks, to_find, true);
    match_artists(tracks, to_find, true);
    match_cds(tracks, to_find, true);
	return 0;
}

