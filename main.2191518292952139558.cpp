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
    out << length.minutes << ':';
    if (length.seconds <= 9)
        out << 0;
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
    int seconds = 0;
    in >> seconds;

    if (0 <= seconds && seconds < 60)
        length.seconds = seconds;
    else
        length.seconds = 0;

    return in;
}

Length operator+ (const Length& a, const Length& b)
{//              
    assert (0 <= a.minutes && 0 <= a.seconds && a.seconds < 60 && 0 <= b.minutes && 0 <= b.seconds && b.seconds < 60) ;
/*                
                                 
*/
    Length return_length = {a.minutes + b.minutes, a.seconds + b.seconds};
    if (return_length.seconds >= 60)
    {
        return_length.seconds -= 60;
        return_length.minutes += 1;
    }

    return return_length;
}

void show_track (Track track, TrackDisplay lt)
{//              
    assert (true) ;
/*                
                                                                                         
*/
    if(lt.showArtist)
        cout << track.artist;
    if(lt.showAlbum)
        cout << " " << track.cd;
    if(lt.showYear)
        cout << " " << track.year;
    if(lt.showTrack)
        cout << " " << track.track;
    if(lt.showTitle)
        cout << " " << track.title;
    if(lt.showTags)
        cout << " " << track.tags;
    if(lt.showLength)
        cout << " " << track.time;
    if(lt.showCountry)
        cout << " " << track.country;
    cout << endl;
}

istream& operator>> (istream& in, Track& track)
{//              
    assert (true) ;
/*                
                                                                                                                 
                                                          
*/
    string temp = "";
    getline(in, track.artist);
    getline(in, track.cd);
    in >> track.year; //          
    getline(in, temp); //            
    in >> track.track; //          
    getline(in, temp); //            
    getline(in, track.title);
    getline(in, track.tags);
    in >> track.time; //             
    getline(in, temp); //            
    getline(in, track.country);
    getline(in, temp); //           
    return in;
}

int match_tracks (vector<Track>& tracks, string track, bool display)
{//              
    assert (! track.empty() && ! tracks.empty()) ;
/*                
                                                                                                                                              
*/
    int found_songs = 0;
    TrackDisplay td = {true, true, true, true, true, true, true, true};
    for(int i=0; i<tracks.size(); i++)
    {
        if (match(track, tracks[i].title))
        {
            found_songs++;
            if(display)
                show_track(tracks[i], td );
        }
    }

    return found_songs;
}

bool unique_artist (vector<string> artists, string new_artist)
{
//              
    assert (! new_artist.empty());
/*                
                                                                                     
*/
    for(int i=0; i<artists.size(); i++)
        if (match(new_artist, artists[i]))
            return false;

    return true;
}

int match_artists (vector<Track>&  tracks, string artist, bool display)
{//              
    assert (! artist.empty() && ! tracks.empty()) ;
/*                
                                                                                                                                             
*/
    vector<string> found_artists;
    TrackDisplay td = {true, false, false, false, false, false, false, false};

    for(int i=0; i<tracks.size(); i++)
    {
        if (match(artist, tracks[i].artist))
        {
            if (unique_artist(found_artists, tracks[i].artist))
            {
                found_artists.push_back(tracks[i].artist);
                if(display)
                    show_track(tracks[i], td);
            }
        }
    }

    return found_artists.size();
}

bool unique_album (vector<string> albums, string new_album)
{//              
    assert (! new_album.empty());
/*                
                                                                                   
*/
    for(int i=0; i<albums.size(); i++)
        if (match(new_album, albums[i]))
            return false;

    return true;
}

int match_cd( vector<Track>& tracks, string artist, bool display)
{//              
    assert (! artist.empty() && ! tracks.empty()) ;
/*                
                                                                                                                                                                                             
*/
    vector<string> found_albums;
    TrackDisplay td = {true, true, true, false, false, false, false, false};

    for(int i=0; i<tracks.size(); i++)
    {
        if (match(artist, tracks[i].artist))
        {
            if (unique_album(found_albums, tracks[i].cd))
            {
                found_albums.push_back(tracks[i].cd);
                if(display)
                    show_track(tracks[i], td);
            }
        }
    }

    return found_albums.size();
}

int number_of_cds (vector<Track>& tracks)
{//              
    assert (! tracks.empty()) ;
/*                
                                                        
*/
    vector<string> found_albums;

    for(int i=0; i<tracks.size(); i++)
        if (unique_album(found_albums, tracks[i].cd))
            found_albums.push_back(tracks[i].cd);

    return found_albums.size();
}

int read_db_from_text(ifstream& inputfile, vector<Track>& readDB)
{//              
    assert (inputfile);
/*                
                                                                                               
*/
    int entries = 0;
    Track temp;
    while (inputfile && entries < 5891)
    {
        inputfile >> temp;
        readDB.push_back(temp);
        entries++;
    }
    return entries;
}

void test_part1 ()
{//              
    assert (true);
/*                
                                       
*/
    Length l1 = {42,42}, l2 = {0,0}, l3 = {3,21}, l4 = {3,14}, l5, l6;
    cin >> l5 >> l6;
    cout << l5 << "\t" << l6 << endl;
    cout << l1 << endl;

    vector<Length> test_length =  {l1, l2, l3, l4};

    for(int i=0; i<4; i++)
    {
        for(int j=i; j<4; j++)
        {
            cout << "i:" << i << " j:" << j << "\t" <<test_length[i] + test_length[j] << endl;
        }
    }
}

void test_part3 ()
{//              
    assert (true);
/*                
                                       
*/
    cout << match_tracks(testDB, "el", true) << endl;
    cout << match_artists(testDB, "el", true) << endl;
    cout << match_cd(testDB, "el", true) << endl;
    cout << number_of_cds(testDB) << endl;
}

int main()
{//              
    assert (true) ;
/*                
                                                                                       
                                                                                        
                                                                                         
                                      
*/
    ifstream inputfile;
    vector<Track> readDB;
    inputfile.open("Tracks.txt");
    int readtracks = read_db_from_text(inputfile, readDB );
    inputfile.close();
    cout << readtracks;
/*
                                                                       
                                       
     
                                  
     
*/
    //             
    //             
	return 0;
}

