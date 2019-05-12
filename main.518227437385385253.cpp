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
    out << length.minutes << ':';
    if (length.seconds < 10)
        out << '0';
    out << length.seconds;
    return out;
}

istream& operator>> (istream& in, Length& length)
{//              
    assert (true) ;
/*                
                                                                                    
*/
    in >> length.minutes;
    in.get();
    in >> length.seconds;
    return in;
}

Length operator+ (const Length& a, const Length& b)
{//              
    assert (0 <= a.minutes && 0 <= a.seconds && a.seconds < 60 && 0 <= b.minutes && 0 <= b.seconds && b.seconds < 60) ;
/*                
                                 
*/
    Length sum;
    sum.seconds = a.seconds + b.seconds;
    sum.minutes = a.minutes + b.minutes;
    if (sum.seconds >= 60) {
        sum.seconds -= 60;
        sum.minutes++;
    }
    return sum;
}

void show(string thing, bool display, bool& shown)
{
//               
    assert(true);
/*                
                                       
                                                                
                        
*/
    if (display) {
        if (shown)
            cout << "; ";
        cout << thing;
        shown = true;
    }
}

void show(int thing, bool display, bool& shown)
{
//               
    assert(true);
/*                
                                       
                                                                
                        
*/
    if (display) {
        if (shown)
            cout << "; ";
        cout << thing;
        shown = true;
    }
}

void show(Length thing, bool display, bool& shown)
{
//               
    assert(true);
/*                
                                       
                                                                
                        
*/
    if (display) {
        if (shown)
            cout << "; ";
        cout << thing;
        shown = true;
    }
}

void show_track (Track track, TrackDisplay td)
{//              
    assert (true) ;
/*                
                                                                                         
*/
    bool shown = false;
    show(track.artist, td.showArtist, shown);
    show(track.cd, td.showAlbum, shown);
    show(track.year, td.showYear, shown);
    show(track.track, td.showTrack, shown);
    show(track.title, td.showTitle, shown);
    show(track.tags, td.showTags, shown);
    show(track.time, td.showLength, shown);
    show(track.country, td.showCountry, shown);
    cout << '\n';
}

istream& operator>> (istream& in, Track& track)
{//              
    assert (true) ;
/*                
                                                                                                                 
                                                          
*/
    string nothing;
    getline(in, track.artist);
    getline(in, track.cd);
    in >> track.year;
    in >> track.track;
    getline(in, nothing);
    getline(in, track.title);
    getline(in, track.tags);
    in >> track.time;
    getline(in, nothing);
    getline(in, track.country);
    getline(in, nothing);
    return in;
}

int match_tracks(vector<Track>& tracks, string track, bool display)
{
//               
    assert(true);
/*                
                                                                       
                                               
*/
    int track_count = 0;
    for (int track_i = 0; track_i < tracks.size(); track_i++) {
        if (match(track, tracks[track_i].title)) {
            track_count++;
            if (display) {
                TrackDisplay td = {true, true, true, true, true, true, true, true};
                show_track(tracks[track_i], td);
            }
        }
    }
    return track_count;
}

int match_artists(vector<Track>& tracks, string artist, bool display)
{
//               
    assert(true);
/*                
                                                                 
                                                
*/
    vector<string> found_artists;
    for (int track_i = 0; track_i < tracks.size(); track_i++) {
        if (match(artist, tracks[track_i].artist)) {
            bool already_found = false;
            for (int artist_i = 0; artist_i < found_artists.size() && !already_found; artist_i++) {
                if (found_artists[artist_i] == tracks[track_i].artist)
                    already_found = true;
            }
            if (!already_found) {
                found_artists.push_back(tracks[track_i].artist);
                if (display) {
                    TrackDisplay td = {true};
                    show_track(tracks[track_i], td);
                }
            }
        }
    }

    return found_artists.size();
}

int match_cds(vector<Track>& tracks, string artist, bool display)
{
//               
    assert(true);
/*                
                                                                              
                                                                                   
*/
    string current_artist = "";
    vector<string> found_albums;
    int album_count = 0;
    for (int track_i = 0; track_i < tracks.size(); track_i++) {
        if(match(artist, tracks[track_i].artist)) {
            if (current_artist != tracks[track_i].artist) {
                while (found_albums.size() > 0)
                    found_albums.pop_back();
                current_artist = tracks[track_i].artist;
            }
            bool already_found = false;
            for (int album_i = 0; album_i < found_albums.size() && !already_found; album_i++) {
                if (found_albums[album_i] == tracks[track_i].cd)
                    already_found = true;
            }
            if (!already_found) {
                found_albums.push_back(tracks[track_i].cd);
                album_count++;

                if (display) {
                TrackDisplay td = {true, true, true};
                show_track(tracks[track_i], td);
                }
            }
        }
    }
    return album_count;
}

int number_of_cds(vector<Track>& tracks)
{
//               
    assert(true);
/*                
                                              
*/
    string current_artist = "";
    string current_cd = "";
    int cd_count = 0;
    for (int track_i = 0; track_i < tracks.size(); track_i++) {
        if (tracks[track_i].cd != current_cd || tracks[track_i].artist != current_artist) {
            current_artist = tracks[track_i].artist;
            current_cd = tracks[track_i].cd;
            cd_count++;
        }
    }
    return cd_count;
}

void read_tracks(ifstream& fin, vector<Track>& tracks)
{
//               
    assert(fin.is_open() && tracks.size() == 0);
/*                
                                          
                                 
*/
    Track track;
    TrackDisplay td = {true, true, true, true, true, true, true, true};
    fin >> track;
    show_track(track, td);
    while (fin) {
        show_track(track, td);
        tracks.push_back(track);
        fin >> track;
    }
}

int main()
{//              
    assert (true) ;
/*                
                                                                                       
                                                                                        
                                                                                         
                                      
*/

    for (int i = 0; i < 2; i++) {
        Length l;
        cout << "Give a track length (mm:ss): ";
        cin >> l;
        cout << "Minutes: " << l.minutes << "\nSeconds: " << l.seconds << "\nOutput: " << l << '\n';
    }
    Length l1 = {42, 42}, l2 = {0, 0}, l3 = {3, 21}, l4 = {3, 14};
    cout << l1 << '\n';
    cout << l2 << '\n';
    cout << l3 << '\n';
    cout << l4 << '\n';
    cout << l1 + l2 << '\n';
    cout << l1 + l3 << '\n';
    cout << l1 + l4 << '\n';
    cout << l2 + l3 << '\n';
    cout << l2 + l4 << '\n';
    cout << l3 + l4 << '\n';

    TrackDisplay td = {true, true, false, true, true, true, true, true};
    show_track(testDB[1], td);
    cout << match_tracks(testDB, "el", true) << '\n';
    cout << match_artists(testDB, "el", true) << '\n';
    cout << match_cds(testDB, "el", true) << '\n';
    cout << match_tracks(testDB, "el", false) << '\n';
    cout << match_artists(testDB, "el", false) << '\n';
    cout << match_cds(testDB, "el", false) << '\n';
    cout << number_of_cds(testDB) << '\n';

    ifstream fin("Tracks.txt");
    vector<Track> tracks;
    read_tracks(fin, tracks);
    fin.close();
    cout << tracks.size();
	return 0;
}

