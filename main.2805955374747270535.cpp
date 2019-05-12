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
    if(length.seconds >= 0 && length.seconds <= 59)
        {
            if(length.minutes < 10) out << 0;
            out << length.minutes << ":";
            if(length.seconds < 10) out << 0;
            out << length.seconds;
        }
    else out << "Invalid length!";
    return out;
/*                
                                                                                          
*/
}

istream& operator>> (istream& in, Length& length)
{//              
    assert (true) ;
    char useless;
    in >> length.minutes
       >> useless
       >> length.seconds;
    return in;

/*                
                                                                                    
*/
}

Length operator+ (const Length& a, const Length& b)
{//              
    assert (0 <= a.minutes && 0 <= a.seconds && a.seconds < 60 && 0 <= b.minutes && 0 <= b.seconds && b.seconds < 60) ;
    Length sum = {(a.minutes + b.minutes), (a.seconds + b.seconds) % 60};
    if(a.seconds + b.seconds >= 60) sum.minutes++;
    return sum;
/*                
                                 
*/
}

void show_track (Track track, TrackDisplay lt)
{//              
    assert (true) ;
    cout << " | ";
    if(lt.showArtist) cout << track.artist << " | ";
    if(lt.showAlbum) cout << track.cd << " | ";
    if(lt.showYear) cout << track.year << " | ";
    if(lt.showTrack) cout << track.track << " | ";
    if(lt.showTitle) cout << track.title << " | ";
    if(lt.showTags) cout << track.tags << " | ";
    if(lt.showLength) cout << track.time << " | ";
    if(lt.showCountry) cout << track.country << " | ";
    cout << endl;

/*                
                                                                                         
*/
}

istream& operator>> (istream& in, Track& track)
{//              
    assert (true) ;
    string a;
    getline(in, a);
    track.artist = a;

    getline(in, a);
    track.cd = a;

    in >> track.year;
    getline(in, a);

    in >> track.track;
    getline(in, a);

    getline(in, a);
    track.title = a;

    getline(in, a);
    track.tags = a;

    in >> track.time;
    getline(in, a);

    getline(in, a);
    track.country = a;

    getline(in, a);

    return in;
/*                
                                                                                                                 
                                                          
*/
}

int match_tracks (vector<Track>& tracks, string track, bool display)
{//              
    assert (true) ;

    TrackDisplay td = {true, true, true, true, true, true, true, true};
    int found = 0;
    for(int i = 0; i < tracks.size(); i++)
    {
        if(match(track, tracks[i].title))
        {
            found++;
            if(display) show_track(tracks[i], td);
        }
    }
    return found;
/*                
                                                                                                   
*/

}

bool string_in_vector (vector<string> v, string s)
{
    for(int i = 0; i < v.size(); i++)
        if(v[i] == s) return true;
    return false;
}

int match_artist (vector<Track>& tracks, string artist, bool display)
{//              
    assert (true) ;

    vector<string> alreadyFound;
    TrackDisplay td = {true, false, false, false, false, false, false, false};
    int found = 0;

    for(int i = 0; i < tracks.size(); i++)
    {
        if(match(artist, tracks[i].artist) && !string_in_vector(alreadyFound, tracks[i].artist))
        {
            found++;
            alreadyFound.push_back(tracks[i].artist);
            if(display) show_track(tracks[i], td);
        }
    }
    return found;
/*                
                                                                                                  
*/
}

int match_cds (vector<Track>& tracks, string artist, bool display)
{//              
    assert (true) ;

    vector<string> alreadyFound;
    TrackDisplay td = {true, true, true, false, false, false, false, false};
    int found = 0;

    for(int i = 0; i < tracks.size(); i++)
    {
        if(match(artist, tracks[i].artist) && !string_in_vector(alreadyFound, tracks[i].cd))
        {
            found++;
            alreadyFound.push_back(tracks[i].cd);
            if(display) show_track(tracks[i], td);
        }
    }
    return found;
/*                
                                                                                           
*/
}

int number_of_cds (vector<Track>& tracks)
{//              
    assert (true) ;

    vector<string> alreadyFound;
    int found = 0;

    for(int i = 0; i < tracks.size(); i++)
    {
        if(!string_in_vector(alreadyFound, tracks[i].cd))
        {
            found++;
            alreadyFound.push_back(tracks[i].cd);
        }
    }
    return found;
/*                
                                             
*/
}

int main()
{//              
    assert (true) ;

    TrackDisplay td = {true, true, true, true, true, true, true, true};
    ifstream track_list;
    Track t1;
    Track t2;
    int readTracks = 0;
    vector<Track> trackDB;

    track_list.open("Tracks.txt");
    if(!track_list)
    {
        cout << "File could not be opened";
        return 1;
    }

    track_list >> t2;

    while(track_list)
    {
        track_list >> t1;
        show_track(t2, td);
        trackDB.push_back(t2);
        t2 = t1;
        readTracks++;
    }
    cout << readTracks << " tracks have been read!" << endl;
    cout << endl << "match_tracks: " << endl;
    match_tracks(trackDB, "el", true);
    cout << endl << "match_artists: " << endl;
    match_artist(trackDB, "el", true);
    cout << endl << "match_cds: " << endl;
    match_cds(trackDB, "el", true);
    int a = number_of_cds(trackDB);
    cout << endl  << "There are " << a << " CDs in the collection!";

/*                
                                                                                       
                                                                                        
                                                                                         
                                      
*/
	return 0;
}

