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

//                                           
Length l1 = {42,42};
Length l2 = {0,0};
Length l3 = {3,21};
Length l4 = {3,14};

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

int size (vector<Track>& v)
{
//                
    assert (true);
//                 
//                                                       
    return static_cast<int> (v.size());
}

ostream& operator<< (ostream& out, const Length& length)
{//              
    assert (0 <= length.minutes && 0<= length.seconds && length.seconds <= 59) ;
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
    in >> length.minutes;
    in.ignore(1, ':');
    in >> length.seconds;
    return in;
}

Length operator+ (const Length& a, const Length& b)
{//              
    assert (0 <= a.minutes && 0 <= a.seconds && a.seconds < 60 && 0 <= b.minutes && 0 <= b.seconds && b.seconds < 60) ;
/*                
                                 
*/
    Length sum;
    sum.minutes = a.minutes + b.minutes + ((a.seconds + b.seconds) / 60);
    sum.seconds = (a.seconds + b.seconds) % 60;
    return sum;
}

void show_track (Track track, TrackDisplay lt)
{//              
    assert (true) ;
/*                
                                                                                         
*/
    if (lt.showArtist)
        cout << track.artist << " ";
    if (lt.showAlbum)
        cout << track.cd << " ";
    if (lt.showYear)
        cout << track.year << " ";
    if (lt.showTrack)
        cout << track.track << " ";
    if (lt.showTitle)
        cout << track.title << " ";
    if (lt.showTags)
        cout << track.tags << " ";
    if (lt.showLength)
        cout << track.time << " ";
    if (lt.showCountry)
        cout << track.country << endl;
}

Track track;

istream& operator>> (istream& in, Track& track)
{//              
    assert (true) ;
/*                
                                                                                                                 
                                                          
*/
    getline(in, track.artist);
    getline(in, track.cd);
    in >> track.year;
    in.ignore(1, '\n');
    in >> track.track;
    in.ignore(1, '\n');
    getline(in, track.title);
    getline(in, track.tags);
    in >> track.time;
    in.ignore(1, '\n');
    getline(in, track.country);
    in.ignore(1, '\n');
    return in;
}

int match_tracks (vector<Track>& tracks, string track, bool display)
{
    //               
    assert (size(tracks) >= 0);
    //                
    //                                                                                                                            
    //                                                                                 
    int matches = 0;
    TrackDisplay all = {true, true, true, true, true, true, true ,true};
    for (int counter = 0; counter < size(tracks); counter++)
    {
        if (match(track, tracks[counter].title))
        {
            matches++;
            if(display)
                show_track(tracks[counter], all);
        }
    }
    return matches;
}

//                                                                                                 
int match_artists (vector<Track>& tracks, string artist, bool display)
{
    //               
    assert (size(tracks) >= 0);
    //                
    //                                                                                                                        
    //                                                                                 
    TrackDisplay only_artist = {true, false, false, false, false, false, false, false};
    string found_artists [size(tracks)];

    int matches = 0;
    for (int counter = 0; counter < size(tracks); counter++)
    {
        if (match(artist, tracks[counter].artist))
        {
            bool found = false;
            for (int counter2 = 0; counter2 < size(tracks); counter2++)
            {
                if (found_artists[counter2] == tracks[counter].artist)
                    found = true;
            }
            if (!found)
            {
                found_artists[matches] = tracks[counter].artist;
                matches++;
                if (display)
                {
                    show_track(tracks[counter], only_artist);
                    cout << endl;
                }
            }
        }
    }
    return matches;

}

//                                                                                             
int match_cds (vector<Track>& tracks, string artist, bool display)
{
    //               
    assert (size(tracks) >= 0);
    //                
    //                                                                                                                   
    //                                                                                                            

    TrackDisplay for_cd = {true, true, true, false, false, false, false, false};
    string found_cds [size(tracks)];

    int matches = 0;
    for (int counter = 0; counter < size(tracks); counter++)
    {
        if (match(artist, tracks[counter].artist))
        {
            bool found = false;
            for (int counter2 = 0; counter2 < size(tracks); counter2++)
            {
                if (found_cds[counter2] == tracks[counter].cd)
                    found = true;
            }
            if (!found)
            {
                found_cds[matches] = tracks[counter].cd;
                matches++;
                if (display)
                {
                    show_track(tracks[counter], for_cd);
                    cout << endl;
                }
            }
        }
    }
    return matches;
}

//                                                                                                 
int number_of_cds (vector<Track>& tracks)
{
    //               
    assert (size(tracks) >= 0);
    //                
    //                                                   

    int matches = 0;
    string number_cds [size(tracks)];
    for (int counter = 0; counter < size(tracks); counter++)
    {
        bool found = false;
        for (int counter2 = 0; counter2 < size(tracks); counter2++)
        {
            if (number_cds[counter2] == tracks[counter].cd)
                found = true;
        }
        if (!found)
        {
            number_cds[matches] = tracks[counter].cd;
            matches++;
        }
    }
    return matches;
}

int main()
{//              
    assert (true) ;
/*                
                                                                                       
                                                                                        
                                                                                         
                                      
*/

    cout << "Opening Tracks.txt" << endl;
    vector<Track> database;
    TrackDisplay show_all = {true, true, true, true, true, true, true, true};
    ifstream input ("Tracks.txt");
    if (!input.is_open())
        {
        cout << "ERROR: unable to open file." << endl;
        return -1;
        }

    input >> track;
    int entries = 0;
    while (input)
    {
        entries++;
        database.push_back(track);
        show_track(track, show_all);
        input >> track;
    }
    cout << "\n\n" << entries << " entries registered\n" << endl;
    input.clear();
    input.close();
    if (!input)
        cout << "WARNING: file was not closed correctly" << endl;
    cout << "The below values are for the testDB vector.\n" << endl;
    cout  << match_tracks(testDB, "el", true) << " matches found\n" << endl;
    cout  << match_artists(testDB, "el", true) << " matches found\n" << endl;
    cout  << match_cds(testDB, "el", true) << " matches found\n" << endl;
    cout  << number_of_cds(testDB) << " total cd's" << endl;

	return 0;
}

