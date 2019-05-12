/*
                                                    
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

struct Length {
	int minutes;							//               
	int seconds;							//                 
};

struct Track {
	string artist;                          //               
	string cd;                              //         
	int    year;                            //                              
	int    track;							//             
	string title;                           //            
	string tags;                            //     
	Length time;							//             
	string country;                         //                             
};

struct TrackDisplay {
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

bool match (string sub, string source) {
    //              
    assert (true) ;
/*                
                                                                                  
*/
    return source.find(sub) != string::npos ;
}

ostream& operator<< (ostream& out, const Length length) {
    //              
    assert (true) ;
/*                
                                                                                          
                                                                                    
*/
    Length output = length;
    while (output.seconds > 59){ //                                                         
        output.minutes ++;
        output.seconds -= 60;
    }
    while (output.seconds < 0){ //                                                  
        output.minutes --;
        output.seconds += 60;
    }
    if (output.minutes < 10 && output.minutes >= 0){
        out << '0';
    }
    out << output.minutes << ':';
    if (output.seconds < 10){
        out << '0';
    }
    out << output.seconds;
    return out;
}

istream& operator>> (istream& in, Length& length) {
    //              
    assert (true) ;
/*                
                                                                                    
                                                                                    
*/
    Length input;
    char dummy;
    in >> input.minutes >> dummy >> input.seconds;
    while (input.seconds > 59){ //                                                         
        input.minutes ++;
        input.seconds -= 60;
    }
    while (input.seconds < 0){ //                                                  
        input.minutes --;
        input.seconds += 60;
    }
    length = input;
    return in;
}

Length operator+ (const Length& a, const Length& b) {
    //              
    assert (0 <= a.minutes && 0 <= a.seconds && a.seconds < 60 && 0 <= b.minutes && 0 <= b.seconds && b.seconds < 60) ;
/*                
                                 
*/
    Length output;
    output.minutes = a.minutes + b.minutes;
    output.seconds = a.seconds + b.seconds;
    while (output.seconds > 59){ //                                                         
        output.minutes ++;
        output.seconds -= 60;
    }
    //                                                                                
    return output;
}

void show_track (Track track, TrackDisplay lt) {
    //              
    assert (true) ;
/*                
                                                                                         
*/
    if (lt.showArtist) cout << "Artist:" << '\t' << '\t' << track.artist << endl;
    if (lt.showAlbum) cout << "Album:" << '\t' << '\t' << track.cd << endl;
    if (lt.showYear) cout << "Year:" << '\t' << '\t' << track.year << endl;
    if (lt.showTrack) cout << "Track:" << '\t' << '\t' << track.track << endl;
    if (lt.showTitle) cout << "Title:" << '\t' << '\t' << track.title << endl;
    if (lt.showTags) cout << "Tags:" << '\t' << '\t' << track.tags << endl;
    if (lt.showLength) cout << "Length:" << '\t' << '\t' << track.time << endl;
    if (lt.showCountry) cout << "Country:" << '\t' << track.country << endl;
	cout << endl;
}

istream& operator>> (istream& in, Track& track) {
    //              
    assert (true) ;
/*                
                                                                                                                 
                                                          
*/
    string dummy;
    getline(in, track.artist);
    getline(in, track.cd);
    in >> track.year;
    getline(in, dummy);
    in >> track.track;
    getline(in, dummy);
    getline(in, track.title);
    getline(in, track.tags);
    in >> track.time;
    getline(in, dummy);
    getline(in, track.country);
    getline(in, dummy);
}

int match_tracks(vector<Track>& tracks, string track, bool display) {
    //              
    assert (true);
    /*                                                                  
                                          */
    int output = 0;
    TrackDisplay all = {true,true,true,true,true,true,true,true};
    for (unsigned int i = 0; i < tracks.size(); i++) {
        if (match(track,tracks[i].title)) output++;
        if (display) show_track(tracks[i], all);
    }
    return output;
}

int match_artists(vector<Track>& tracks, string artist, bool display) {
    //              
    assert (true);
    /*                                                                                     
                                      */
    int output = 0;
    vector<string> artists;
    bool found;
    TrackDisplay artist_only = {true,false,false,false,false,false,false,false};
    for (unsigned int i = 0; i < tracks.size(); i++) {
        found = false;
        if (match(artist,tracks[i].artist)) {
            for (unsigned int j = 0; j < artists.size(); j++){
                if (artists[j] == tracks[i].artist) found = true;
            }
            if (!found) {
                artists.push_back(tracks[i].artist);
                output++;
                if (display) show_track(tracks[i], artist_only);
            }
        }
    }
    return output;
}

int match_cds(vector<Track>& tracks, string artist, bool display) {
    //              
    assert (true);
    /*                                                                                                         
                                                */
    int output = 0;
    vector<string> cds;
    bool found;
    TrackDisplay art_cd_yr = {true,true,true,false,false,false,false,false};
    for (unsigned int i = 0; i < tracks.size(); i++) {
        found = false;
        if (match(artist,tracks[i].artist)) {
            for (unsigned int j = 0; j < cds.size(); j++){
                if (cds[j] == tracks[i].cd) found = true;
            }
            if (!found) {
                cds.push_back(tracks[i].cd);
                output++;
                if (display) show_track(tracks[i], art_cd_yr);
            }
        }
    }
    return output;
}

int number_of_cds(vector<Track>& tracks) {
    //              
    assert (true);
    /*                                                     */
    int output = 0;
    vector<string> cds;
    bool found;
    TrackDisplay art_cd_yr = {true,true,true,false,false,false,false,false};
    for (unsigned int i = 0; i < tracks.size(); i++) {
        found = false;
        for (unsigned int j = 0; j < cds.size(); j++){
            if (cds[j] == tracks[i].cd) found = true;
        }
        if (!found) {
            cds.push_back(tracks[i].cd);
            output++;
        }
    }
    return output;
}

bool open_input_file (ifstream& infile, string infile_name) {
//                
    assert(!infile.is_open());
//                                                                               
    infile.open(infile_name.c_str());
    if (!infile.is_open()) {
        cout << "Error: Input file " << infile_name << " could not be opened." << endl;
        return false;
    }
    cout << "The file " << infile_name << " has been opened successfully." << endl;
    return true;
}

int main(){
    //              
    assert (true) ;
/*                
                                                                                       
                                                                                        
                                                                                         
                                      
*/
    ifstream inputfile;
    if (!open_input_file(inputfile, "Tracks.txt")) return -1;
    Track track;
    vector<Track> database;
    while (inputfile){
        inputfile >> track;
        database.push_back(track);
    }
    database.pop_back(); //                                                                              
    int n;
    n = match_tracks(database, "", true);
    cout << "There are " << n << " tracks." << endl;
    n = match_artists(database, "", false);
    cout << "There are " << n << " artists." << endl;
    n = number_of_cds(database);
    cout << "There are " << n << " cds."<< endl;
	return 0;
}

