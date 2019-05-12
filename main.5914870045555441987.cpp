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

//               
ostream& operator<< (ostream& out, const Length length)
{
    //              
    assert (true) ;
    //               
    //                                                                                        

    out << length.minutes << ":" << length.seconds;
    return out;

}

istream& operator>> (istream& in, Length& length)
{
    //              
    assert (true) ;
    //               
    //                                                                                  

    char c;
    in >> length.minutes >> c >> length.seconds;
    return in;

}

Length operator+ (const Length& a, const Length& b)
{
    //              
    assert (0 <= a.minutes && 0 <= a.seconds && a.seconds < 60 && 0 <= b.minutes && 0 <= b.seconds && b.seconds < 60) ;
    //               
    //                              

    Length sum;
    int rest;
    int quotient;
    sum.minutes = a.minutes + b.minutes;
    sum.seconds = a.seconds + b.seconds;

    if (sum.seconds > 59)
    {
        rest = sum.seconds % 60;
        quotient = (sum.seconds - rest)/60;
        sum.seconds = rest;
        sum.minutes += quotient;
    }

    //                                                   
    if (sum.minutes >= 0 && sum.minutes <= 9)
        cout << "0" << sum.minutes << ":";
    else
        cout << sum.minutes << ":";

    if (sum.seconds >= 0 && sum.seconds <= 9)
        cout << "0" << sum.seconds << endl;
    else
        cout << sum.seconds << endl;

    return sum;

}

//               
void show_track (Track track, TrackDisplay td)
{
    //              
    assert (true) ;
    //               
    //                                                                                      

    if (td.showArtist)
        cout << track.artist << endl;
    if (td.showAlbum)
        cout << track.cd << endl;
    if (td.showYear)
        cout << track.year << endl;
    if (td.showTrack)
        cout << track.track << endl;
    if (td.showTitle)
        cout << track.title << endl;
    if (td.showTags)
        cout << track.tags << endl;
    if (td.showLength)
        cout << track.time << endl;
    if (td.showCountry)
        cout << track.country << endl;

}

//               
bool match (string sub, string source)
{
    //              
    assert (true);
    //               
    //                                                                               

    return source.find(sub) != string::npos;

}

int match_tracks (vector<Track>& tracks, string track, bool display)
{
    //              
    assert(true);
    //               
    //                                                                                                                                            
    //                                                                                                                                  

    display = false;
    int counter = 0;
    for (int i = 0; i < tracks.size(); i++)
    {
        if (match(track, tracks[i].title))
        {
            display = true;
            show_track(tracks[i], {display, display, display, display, display, display, display, display});
            cout << endl;
            counter++;
        }
    }
    return counter;

}

int match_artists (vector<Track>& tracks, string artist, bool display)
{
    //              
    assert(true);
    //               
    //                                                                                                                           
    //                                                                                                                                    

    display = false;
    int counter = 0;
    for (int i = 0; i < tracks.size(); i++)
    {
        if (match(artist, tracks[i].artist))
        {
            display = true;
            if (i == 0 || tracks[i-1].artist != tracks[i].artist)
            {
                show_track(tracks[i], {display, false, false, false, false, false, false, false});
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
    //               
    //                                                                                                                                      
    //                                                                                                                                      
    //                                 

    display = false;
    int counter = 0;
    for (int i = 0; i < tracks.size(); i++)
    {
        if (match(artist, tracks[i].artist))
        {
            display = true;
            if (i == 0 || tracks[i-1].cd != tracks[i].cd)
            {
                show_track(tracks[i], {display, display, display, false, false, false, false, false});
                cout << endl;
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
    //               
    //                                           

    vector<string> CD;
    CD.push_back(tracks[0].cd);
    for (int i = 1; i < tracks.size(); i++)
        if (tracks[i-1].cd != tracks[i].cd)
            CD.push_back(tracks[i].cd);
    //                                            
    cout << CD.size() << endl;
    return CD.size();

}

//               
void open_file(ifstream& database)
{
    //              
    assert (true) ;
    //               
    //                        

    cout << "Which file would you like to open?" << endl;
    string filename;
    cin >> filename;
    database.open (filename.c_str());
    if (database.is_open())
        cout << "File successfully opened" << endl;
    else
    {
        cout << "File could not be opened" << endl;
        return;
    }

}

istream& operator>> (istream& in, Track& track)
{
    //              
    assert (true) ;
    //               
    //                                                                                                              
    //                                                       

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
    return in;

}

int main()
{
    //              
    assert (true) ;
    //               
    //                                                                                    
    //                                                                                     
    //                                                                                      
    //                                   

    cout << "*** PART 1 ***" << endl;
    Length l1 = {42,42}, l2 = {0,0}, l3 = {3,21}, l4 = {3,14};

    cout << "* TESTING IMPLEMENTATION OF << :" << endl;
    cout << l1 << endl;
    cout << l2 << endl;
    cout << l3 << endl;
    cout << l4 << endl;
    cout << endl;

    cout << "* TESTING IMPLEMENTATION OF >> :" << endl;
    cout << "Please use the format mm:ss with mm bigger or equal to 0 and ss between 0 and 59" << endl;
    cin >> l1;
    cin >> l2;
    cout << endl;

    cout << "* TESTING IMPLEMENTATION OF + :" << endl;
    operator+ (l1, l2);
    operator+ (l1, l3);
    operator+ (l1, l4);
    operator+ (l2, l3);
    operator+ (l2, l4);
    operator+ (l3, l4);
    cout << endl;
    cout << endl;

    cout << "*** PART 3 ***" << endl;
    string s = "el";

    cout << "* TESTING IMPLEMENTATION OF match_tracks WITH STRING EL :" << endl;
    match_tracks(testDB, s, true);

    cout << "* TESTING IMPLEMENTATION OF match_artists WITH STRING EL :" << endl;
    match_artists(testDB, s, true);
    cout << endl;

    cout << "* TESTING IMPLEMENTATION OF match_cds WITH STRING EL :" << endl;
    match_cds(testDB, s, true);

    cout << "* TESTING IMPLEMENTATION OF number_of_cds :" << endl;
    number_of_cds(testDB);
    cout << endl;
    cout << endl;

    cout << "*** PART 4 ***" << endl;

    ifstream database;
    open_file(database);
    Track track;
    int counter = 0;
    while  (!database.eof())
    {
        database >> track;
        show_track(track, {true, true, true, true, true, true, true, true});
        cout << endl;
        counter++;
    }
    cout << "Number of entries read: " << counter << endl;

	return 0;
}

