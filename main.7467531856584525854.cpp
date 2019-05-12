/*
                         
                          
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>
#include <sstream>

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

vector<Track> readDB;

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
    string seconds = to_string(length.seconds);
    string minutes = to_string(length.minutes);
    if (length.minutes < 10) {
        minutes = "0" + to_string(length.minutes);
    }
    if (length.seconds < 10) {
        seconds = "0" + to_string(length.seconds);
    }
    cout << minutes << ":" << seconds;
    return cout;
}

istream& operator>> (istream& in, Length& length)
{//              
    assert (true) ;
/*                
                                                                                    
*/
    char c;
    string minutes;
    string seconds;
    bool limit = false;
    while (in.get(c) && c != '\n') {
        if (c == ':') {
            limit = true;
        } else {
            if (limit) {
                seconds += c;
            } else {
                minutes += c;
            }
        }
    }
    length.minutes = stoi(minutes);
    length.seconds = stoi(seconds);
    return in;
}

Length operator+ (const Length& a, const Length& b)
{//              
    assert (0 <= a.minutes && 0 <= a.seconds && a.seconds < 60 && 0 <= b.minutes && 0 <= b.seconds && b.seconds < 60) ;
/*                
                                 
*/
    int newminutes = a.minutes + b.minutes;
    int newseconds = a.seconds + b.seconds;
    Length newlength = {newminutes, newseconds};
    if (newseconds <= 59) {
        return newlength;
    }
    newlength.minutes++;
    newlength.seconds -= 60;
    return newlength;
}

void show_track (Track track, TrackDisplay lt)
{//              
    assert (true) ;
/*                
                                                                                         
*/
    if (lt.showTitle) {
        cout << "Title: " << track.title << endl;
    }
    if (lt.showArtist) {
        cout << "Artist: " << track.artist << endl;
    }
    if (lt.showAlbum) {
        cout << "Album: " << track.cd << endl;
    }
    if (lt.showTrack) {
        cout << "Tracknumber: " << track.track << endl;
    }
    if (lt.showLength) {
        cout << "Length: ";
        cout << track.time;
        cout << endl;
    }
    if (lt.showCountry) {
        cout << "Country of release: " << track.country << endl;
    }
    if (lt.showYear) {
        cout << "Year of release: " << track.year << endl;
    }
    if (lt.showTags) {
        cout << "Tags: " << track.tags << endl;
    }
    cout << endl;
}

int match_tracks(vector<Track>& tracks, string track, bool display) {
    //              
    assert(true);
    //               
    //                                                                            
    //                                                                                                               
    const TrackDisplay showparams = {true, true, true, true, true, true, true, true};
    int count = 0;
    for (int i = 0; i < tracks.size(); i++) {
        if (match(track, tracks.at(i).title)) {
            count++;
            if (display) {
                show_track(tracks.at(i), showparams);
            }
        }
    }
    return count;
}

int match_artists(vector<Track>& tracks, string artist, bool display) {
    //              
    assert(true);
    //               
    //                                                                            
    //                                                                                                           
    vector<Track> matches;
    for (int i = 0; i < tracks.size(); i++) {
        if (match(artist, tracks.at(i).artist)) {
            bool alreadyfound = false;
            for (int j = 0; j < matches.size(); j++) {
                alreadyfound = matches.at(j).artist == tracks.at(i).artist;
            }
            if (!alreadyfound) {
                matches.push_back(tracks.at(i));
            }
        }
    }
    if (display) {
        const TrackDisplay showparams = {true, false, false, false, false, false, false, false};
        for (int i = 0; i < matches.size(); i++) {
            show_track(matches.at(i), showparams);
        }
    }
    return matches.size();
}

int match_cds(vector<Track>& tracks, string artist, bool display) {
    //              
    assert(true);
    //               
    //                                                                            
    //                                                                                                               
    vector<Track> matches;
    for (int i = 0; i < tracks.size(); i++) {
        if (match(artist, tracks.at(i).artist)) {
            bool alreadyfound = false;
            for (int j = 0; j < matches.size(); j++) {
                alreadyfound = matches.at(j).cd == tracks.at(i).cd;
            }
            if (!alreadyfound) {
                matches.push_back(tracks.at(i));
            }
        }
    }
    if (display) {
        const TrackDisplay showparams = {true, true, true, false, false, false, false, false};
        for (int i = 0; i < matches.size(); i++) {
            show_track(matches.at(i), showparams);
        }
    }
    return matches.size();
}

int number_of_cds(vector<Track>& tracks) {
    //              
    assert(true);
    //               
    //                                                      
    vector<string> found;
    for (int i = 0; i < tracks.size(); i++) {
        bool alreadyfound = false;
        for (int j = 0; j < found.size(); j++) {
            alreadyfound = found.at(j) == tracks.at(i).cd;
        }
        if (!alreadyfound) {
            found.push_back(tracks.at(i).cd);
        }
    }
    return found.size();
}

istream& operator>> (istream& in, Track& track)
{//              
    assert (true) ;
/*                
                                                                                                                 
                                                          
*/
    string linebreak;
    getline(in, linebreak);
    if (linebreak.empty()) {
        getline(in, track.artist);
        if (track.artist.empty()) {
            return in;
        }
    } else {
        track.artist = linebreak;
    }
    getline(in, track.cd);
    string yearstring;
    getline(in, yearstring);
    track.year = stoi(yearstring);
    string tracknumstring;
    getline(in, tracknumstring);
    track.track = stoi(tracknumstring);
    getline(in, track.title);
    getline(in, track.tags);
    Length length;
    string l;
    stringstream ss;
    getline(in, l);
    ss << l;
    ss >> length;
    track.time = length;
    getline(in, track.country);
    return in;
}

int main() {
    //              
    assert (true) ;

/*                
                                                                                       
                                                                                        
                                                                                         
                                      
*/

    //                
    string read;
    cout << "Enter filename:";
    cin >> read;
    cin.clear();
    cin.ignore(999, '\n');
    ifstream stream(read);
    if (stream.is_open()) {
        Track track;
        int count = 0;
        while (stream >> track) {
            count++;
            readDB.push_back(track);
        }
        cout << count << " entries read" << endl << endl;
    } else {
        cout << "File could not be opened";
    }

    //                                      
    cout << "Enter time in format mm:ss" << endl;
    Length l;
    cin >> l;
    cout << "Read from cin minutes: " << l.minutes << ", seconds: " << l.seconds << endl;
    cout << endl;

    Length l1 = {42,42}, l2 = {0,0}, l3 = {3,21}, l4 = {3,14};
    Length add;
    add = l1 + l2;
    cout << "l1 + l2 = " << add << endl;
    add = l1 + l3;
    cout << "l1 + l3 = " << add << endl;
    add = l1 + l4;
    cout << "l1 + l4 = " << add << endl;
    add = l2 + l3;
    cout << "l2 + l3 = " << add << endl;
    add = l2 + l4;
    cout << "l2 + l4 = " << add << endl;
    add = l3 + l4;
    cout << "l3 + l4 = " << add << endl;
    add = l1 + l1;
    cout << "l1 + l1 = " << add << endl;
    add = l2 + l2;
    cout << "l2 + l2 = " << add << endl;
    add = l3 + l3;
    cout << "l3 + l3 = " << add << endl;
    add = l4 + l4;
    cout << "l4 + l4 = " << add << endl;
    cout << endl;

    //       
    cout << match_tracks(testDB, "el", true) << endl << endl;
    cout << match_artists(testDB, "el", true) << endl << endl;
    cout << match_cds(testDB, "Adele", true) << endl << endl;
    cout << number_of_cds(testDB);
    return 0;
}
