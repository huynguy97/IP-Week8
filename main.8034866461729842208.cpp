#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>

//                                
//                            

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
    out << length.minutes
        << ":"
        << length.seconds;
    return out;
}

istream& operator>> (istream& in, Length& length)
{//              
    assert (true) ;
/*                
                                                                                    
*/
    in >> length.minutes
       >> length.seconds;
    return in;
}

Length operator+ (const Length& a, const Length& b)
{//              
    assert (0 <= a.minutes && 0 <= a.seconds && a.seconds < 60 && 0 <= b.minutes && 0 <= b.seconds && b.seconds < 60) ;
/*                
                                 
*/
    int total_seconds = (a.seconds + b.seconds)%60;
    int total_minutes = a.minutes + b.minutes + (a.seconds + b.seconds) / 60;
    Length c = {total_minutes, total_seconds};
    return c;
}

void show_track (Track track, TrackDisplay td)
{//              
    assert (true) ;
/*                
                                                                                         
*/
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

int match_tracks(vector<Track>& tracks, string track, bool display)
{//              
    assert (true) ;
/*                
                                                                                                        
                                                                                                         
                                                                                                      
*/
    int counter = 0;
    TrackDisplay td = {true, true, true, true, true, true, true, true};
    for (int i = 0; i < testDB.size(); i++)
    {
        Track source = tracks [i];
        if (match (track, source.title))
        {
            counter++;
            if (display)
            {
                show_track(source, td);
                cout << endl;
            }

        }
    }
    return counter;
}

bool search_vector(const vector<string>& find_vector, string find_string)
{//              
    assert (true) ;
/*                
                                                                                     
*/
    for (int i = 0; i < find_vector.size(); i++)
    {
        if (find_vector[i] == find_string)
            return true;
    }
    return false;
}

int match_artists(vector<Track>& tracks, string track, bool display)
{//              
    assert (true) ;
/*                
                                                                                                                      
                                                                                                      
*/
    int counter = 0;
    TrackDisplay td = {true, false, false, false, false, false, false, false};
    vector<string> ArtistList;
    for (int i = 0; i < testDB.size(); i++)
    {
        Track source = tracks [i];
        if (match (track, source.artist) && !search_vector(ArtistList, source.artist))
        {
            counter++;
            ArtistList.push_back(source.artist);
            if (display)
            {
                show_track(source, td);
                cout << endl;
            }

        }
    }
    return counter;
}

int match_cds(vector<Track>& tracks, string track, bool display)
{//              
    assert (true) ;
/*                
                                                                                                                                   
                                                                                                      
*/
    int counter = 0;
    TrackDisplay td = {true, true, true, false, false, false, false, false};
    vector<string> CDList;
    for (int i = 0; i < testDB.size(); i++)
    {
        Track source = tracks [i];
        if (match (track, source.artist) && !search_vector(CDList, source.cd))
        {
            counter++;
            CDList.push_back(source.cd);
            if (display)
            {
                show_track(source, td);
                cout << endl;
            }

        }
    }
    return counter;
}

int number_of_cds(vector<Track>& tracks)
{//              
    assert (true) ;
/*                
                                                                                               
*/
    int counter = 0;
    vector<string> CDList;
    for (int i = 0; i < testDB.size(); i++)
    {
        Track source = tracks [i];
        if (!search_vector(CDList, source.cd))
        {
            counter++;
            CDList.push_back(source.cd);
        }
    }
    return counter;
}

istream& operator>> (istream& in, Track& track)
{//              
    assert (true) ;
/*                
                                                                                                                 
                                                          
*/
    in >> track.artist
       >> track.cd
       >> track.year
       >> track.track
       >> track.title
       >> track.tags
       >> track.time
       >> track.country;
    return in;
}

int main()
{//              
    assert (true) ;
/*                
                                                                                       
                                                                                        
                                                                                         
                                      
*/
    //         
    //         
    //         
    //         
    //              
    //                                                                                                                                                                               
    //                                                                   
    //                      
    bool display = true;
    //                                                    
    //                                                     
    //                                                 
    //                                      
    //            
    //             
    string filename = "Tracks.txt";
    ifstream inputfile (filename);
    string outputline;
    string output_track = "\"";
    vector<Track> trackDB;
    int line_counter = 0;
    int track_counter = 0;
    Track track;
    if (inputfile.is_open())
    {
        cout << "Opened";
    }
    while (inputfile)
    {
        line_counter++;
        if (getline(inputfile, outputline) && outputline != "")
        {
            cout << outputline << endl;
            if (line_counter == 8)
            {
                line_counter = 0;
                track_counter++;
            }
        }
        inputfile >> track;
        trackDB.push_back(track);

    }
    cout << track_counter;
	return 0;
}

