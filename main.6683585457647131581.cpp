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
        ,"alternative,rock,instrumental",     { 2,33},"U.S.A."
    }
    ,{"All them witches",               "Dying surfer meets his maker",2015,8, "Talisman",                    "alternative,rock",                  { 6, 7},"U.S.A."}
    ,{"All them witches",               "Dying surfer meets his maker",2015,9, "Blood and sand / milk and endless waters","alternative,rock",      { 7,20},"U.S.A."}
    ,{"The decemberists",               "The tain",                    2005,1, "The tain (parts i-iv)",       "progressive,experimental,folk,rock",{18,35},"U.S.A."}
    ,{"Colin Stetson and Sarah Neufeld","Never were the way she was",  2015,1, "The sun roars into view",     "jazz,instrumental,experimental",    { 7,37},"U.S.A.,Canada"}
    ,{"Colin Stetson and Sarah Neufeld","Never were the way she was",2015,2, "Won't be a thing to become",  "jazz,instrumental,experimental",    { 3,24},"U.S.A.,Canada"}
    ,{"Colin Stetson and Sarah Neufeld","Never were the way she was",  2015,3, "In the vespers",              "jazz,instrumental,experimental",    { 6, 2},"U.S.A.,Canada"}
    ,{"Colin Stetson and Sarah Neufeld","Never were the way she was",  2015,4, "And still they move",         "jazz,instrumental,experimental",    { 2,56},"U.S.A.,Canada"}
    ,{"Colin Stetson and Sarah Neufeld","Never were the way she was",  2015,5, "With the dark hug of time",   "jazz,instrumental,experimental",    { 6,34},"U.S.A.,Canada"}
    ,{"Colin Stetson and Sarah Neufeld","Never were the way she was",  2015,6, "The rest of us",              "jazz,instrumental,experimental",    { 6,30},"U.S.A.,Canada"}
    ,{"Colin Stetson and Sarah Neufeld","Never were the way she was",  2015,7, "Never were the way she was",  "jazz,instrumental,experimental",    { 8,12},"U.S.A.,Canada"}
    ,{"Colin Stetson and Sarah Neufeld","Never were the way she was",  2015,8, "Flight",                      "jazz,instrumental,experimental",    { 1,38},"U.S.A.,Canada"}
} ;

bool match (string sub, string source)
{
    //              
    assert (true) ;
    /*                
                                                                                      
    */
    return source.find(sub) != string::npos ;
}

ostream& operator<< (ostream& out, const Length& length)
{
    //              
    assert (true) ;
    /*                
                                                                                              
    */
//               
    if ( length.seconds < 10 )
    {
        out <<  length.minutes << ':'
            <<  '0' << length.seconds;
    }
    else
    {
        out << length.minutes << ':'
            << length.seconds ;
    }
    return out ;

}

istream& operator>> (istream& in, Length& length)
{
    //              
    assert (true) ;
    /*                
                                                                                        
    */
    //              
    char c ;
    in >> length.minutes >> c >> length.seconds;

    if (length.seconds > 59)
    {
        int minup = length.seconds / 60;
        int rest  = length.seconds % 60;
        length.minutes += minup;
        length.seconds = rest;
    }

    return in;
}

Length operator+ (const Length& a, const Length& b)
{
    //              
    assert (0 <= a.minutes && 0 <= a.seconds && a.seconds < 60 && 0 <= b.minutes && 0 <= b.seconds && b.seconds < 60) ;
    /*                
                                     
    */
    //               
    Length sumlength ;
    sumlength.minutes = a.minutes + b.minutes + ((a.seconds + b.seconds)/60);
    sumlength.seconds = (a.seconds + b.seconds)%60;

    return sumlength;

}

void show_track (Track track, TrackDisplay lt)
{
    //              
    assert (true) ;
    /*                
                                                                                             
    */
    //               
    /*                                                       
                                  */
    if (lt.showTrack)
    {
        cout << track.artist << endl;
        cout << track.cd << endl;
        cout << track.year << endl;
        cout << track.track << endl;
        cout << track.title << endl;
        cout << track.time << endl;
        cout << track.tags << endl;
        cout << track.country << '\n' << endl;
    }
    if (lt.showArtist)
    {
        cout << track.artist << '\n' << endl;
    }
    if (lt.showAlbum)
    {
        cout << track.artist << endl;
        cout << track.cd << endl;
        cout << track.year << '\n' << endl;
    }
}

istream& operator>> (istream& in, Track& track)
{
    //              
    assert (true) ;
    /*                
                                                                                                                     
                                                              
    */
    string str;
    getline (in, track.artist);
    getline (in, track.cd);
    in >> track.year;
    in >> track.track;
    in.ignore();
    getline (in, track.title);
    getline (in, track.tags);
    in >> track.time;
    in.ignore();
    getline (in, track.country);
    getline (in, str);
    return in;
}

int match_tracks(vector<Track>& tracks, string track, bool display)
{
    cout << "***Searching for tracks:**" << endl;
    TrackDisplay lt = {false,false,false,true,false,false,false,false};
    int counter = 0;
    for (int i = 0; i < 41 ; i++)
    {
        if (match(track, tracks[i].title))
        {
            counter++;
            if (display)
            {
                show_track(tracks[i], lt);
            }
        }
    }
    return counter;
}

int match_artists(vector<Track>& tracks, string track, bool display)
{
    cout << "**Searching for artists:**" << endl;
    TrackDisplay lt = {true,false,false,false,false,false,false,false};
    int counter = 0;
    for (int i = 0; i < 41 ; i++)
    {
        if (match(track, tracks[i].artist))
        {
            if (tracks[i-1].artist != tracks[i].artist)
            {
                counter++;
                if (display)
                {
                    show_track(tracks[i], lt);
                }
            }
        }
    }
    return counter;
}

int match_cds(vector<Track>& tracks, string track, bool display)
{
    cout << "**Searching for Cds of Artist**" << endl;
    TrackDisplay lt = {false,true,false,false,false,false,false,false};
    int counter = 0;
    for (int i = 0; i < 41 ; i++)
    {
        if (match(track, tracks[i].artist))
        {
            if (tracks[i-1].cd != tracks[i].cd)
            {
                counter++;
                if (display)
                {
                    show_track(tracks[i], lt);
                }
            }
        }
    }
    return counter;
}

int number_of_cds(vector<Track>& tracks)
{
    int counter=0;
    for (int d = 0 ; d < 41; d++)
    {
        if (tracks[d].cd != tracks[d+1].cd )
        {
            counter++;
        }
    }
    return counter;
}

int read_file (ifstream& inputfile, vector<Track>& Database)
{
//             
    assert (inputfile.is_open());
//              
    //                         
    //                                         
    //                                                   
    //                                      
    Track track;
    TrackDisplay displays = {true,true,true,true,true,true,true,true};
    while (inputfile)
    {
        inputfile >> track;
        Database.push_back(track);
    }
    cout << "There are " << Database.size() << " entries." << endl;
    return Database.size();
}

int main()
{
    //              
    assert (true) ;
    /*                
                                                                                           
                                                                                            
                                                                                             
                                          
    */
    //               
    cout << "**Part1**" << endl;
    cout << "Length output test:" << endl;
    Length outtest1 = {20,57};
    Length outtest2 = {01,19};
    cout << outtest1 << endl;
    cout << outtest2 << endl;
    cout << "Length input test:" << endl;
    cout << "Give Length in form: 'mm:ss'" << endl;
    Length intest1, intest2;
    cin  >> intest1;
    cout << intest1 << endl;
    cin  >> intest2;
    cout << intest2 << endl;
    cout << "Length operator test:" << endl;
    Length l1 = {42,42}, l2 = {0,0}, l3 = {3,21}, l4 = {3,14};
    cout << l1 + l2 << endl;
    cout << l1 + l3 << endl;
    cout << l1 + l4 << endl;
    cout << l2 + l3 << endl;
    cout << l3 + l4 << endl;
    cout << "**Part3**" << endl;
    cout << "For what do you want to search?" << '\n'
         << "1 = searching for tracks" << '\n'
         << "2 = searching for artist" << '\n'
         << "3 = searching for albums of artist" << endl;
    int choice;
    cin >> choice;
    cout << "What should the program search for?" << endl;
    string query;
    cin >> query;
    switch (choice)
    {
    case 1:
        match_tracks(testDB,query,true);
        break;
    case 2:
        match_artists(testDB,query,true);
        break;
    case 3:
        match_cds(testDB,query,true);
        break;
    default:
        cout << choice << " is not a valid choice! Program stops!" << endl;
    }
    number_of_cds(testDB);
    cout << "**Part4**" << endl;
    vector<Track> Database;
    ifstream inputfile ("Tracks.txt");
    read_file(inputfile,Database);

    return 0;
}

