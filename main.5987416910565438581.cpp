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

vector<Track> database;

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
    out << length.minutes << ':' << length.seconds;
    return out;
}

istream& operator>> (istream& in, Length& length)
{//              
    assert (true) ;
/*                
                                                                                    
*/
    char c;
    in >> length.minutes >> c >> length.seconds;
    return in;
}

Length operator+ (const Length& a, const Length& b)
{//              
    assert (0 <= a.minutes && 0 <= a.seconds && a.seconds < 60 && 0 <= b.minutes && 0 <= b.seconds && b.seconds < 60) ;
/*                
                                 
*/
    Length sum;
    sum.minutes = a.minutes + b.minutes;
    if ((a.seconds + b.seconds) > 59)
    {
        sum.minutes++;
        sum.seconds = a.seconds + b.seconds - 60;
    }
    else
        sum.seconds = a.seconds + b.seconds;
    return sum;
}

void show_track (Track track, TrackDisplay lt)
{//              
    assert (true) ;
/*                
                                                                                         
*/
    if (lt.showArtist)
        cout << "Artist: " << track.artist << endl;
    if (lt.showAlbum)
        cout << "Album: " << track.cd << endl;
    if (lt.showYear)
        cout << "Year: " << track.year << endl;
    if (lt.showTitle)
        cout << "Title: " << track.title << endl;
    if (lt.showTrack)
        cout << "Track: " << track.track << endl;
    if (lt.showTags)
        cout << "Tags: " << track.tags << endl;
    if (lt.showLength)
    {
        Length time = track.time;
        cout << "Playtime: " << time << endl;
    }
    if (lt.showCountry)
        cout << "Country: " << track.country << endl;

}
/*
	                                                         
	                                                   
	                                                                        
	             							               
	                                                      
	                                               
	            							               
	               
*/
istream& operator>> (istream& in, Track& track)
{//              
    assert (true) ;
/*                
                                                                                                                 
                                                          
*/

    in >> track.artist >> track.cd >> track.year >> track.track
       >> track.title >> track.tags >> track.time >> track.country;
    return in;
}

int match_tracks (vector<Track> & tracks, string track, bool display)
{
    //             
    assert(track != "");
    //              
    //                          
    int counter = 0;
    int vector_size = tracks.size();

    //                                                
    for(int i = 0; i < vector_size; i++)
        //                                
        if (match(track, tracks[i].title))
        {
            //                                                  
            if (display)
            {
                TrackDisplay information = {true, true, true, true,
                                            true, true, true, true};
                show_track(testDB[i], information);
                cout << endl;
            }
            //                                    
            counter++;
        }
        //                           
        cout << "There are " << counter << " tracks found with a title that "
             << "matches \'" << track << "\'." << endl;

}

int match_artists (vector<Track> & tracks, string artist, bool display)
{
    //             
    assert(artist != "");
    //              
    int tracks_size = tracks.size();    //                               
    int fa_size = 0;                    //                                   
    bool unknown = true;
    //                                         
    vector<string> found_artists;

    //                                                 
    for (int i = 0; i < tracks_size; i++)
        //                                                                 
        //                    
        if (match(artist, tracks[i].artist))
        {
            fa_size = found_artists.size();
            //                                               
            for (int j = 0; j < fa_size; j++)
                if (found_artists[j] == tracks[i].artist)
                    unknown = false;

            //                                               
            if (unknown)
            {
                found_artists.push_back(tracks[i].artist);
                TrackDisplay information = {true};
                //                                                     
                if (display)
                {
                    show_track(testDB[i], information);
                    cout << endl;
                }
            }
            else
                unknown = true;
        }
    cout << "There were " << fa_size << " artists found, whose name "
         << "matches \'" << artist << "\'." << endl;
}

int match_cds (vector<Track>& tracks, string artist, bool display)
{
    //             
    assert(artist != "");
    //              
    //                                                              
    int counter = 0;
    bool unknown = true;
    int tracks_size = tracks.size();
    int albums_size = 0;
    vector<string> albums;

    //                                                   
    for (int i = 0; i < tracks_size; i ++)
        //                                                                
        if(match(artist, tracks[i].artist))
        {
            albums_size = albums.size();
            //                                          
            for (int j = 0; j < albums_size; j++)
            {
                if (albums[j] == tracks[i].cd)
                    unknown = false;
            }
            //                                                 
            if (unknown)
            {
                albums.push_back(tracks[i].cd);
                if (display)
                {
                    TrackDisplay information = {true,true,true};
                    show_track(testDB[i],information);
                    cout << endl;
                }
                counter++;
            }
            //                   
            else
                unknown = true;
        }
    //                              
    cout << "There were " << counter << " albums found." << endl;
}

int number_of_cds (vector<Track> & tracks)
{
    //             
    assert(tracks.size() != 0);
    //              
    //                                                         
    int counter = 0, fcds_size = 0, tracks_size = tracks.size();
    bool unknown = true;
    vector<string> found_cds;

    //                                       
    for (int i = 0; i < tracks_size; i++)
    {
        fcds_size = found_cds.size();
        //                                           
        for (int j = 0; j < fcds_size; j++)
            if (found_cds[j] == tracks[i].cd)
                unknown = false;
        //                                              
        if (unknown)
        {
            found_cds.push_back(tracks[i].cd);
            counter++;
        }
        //                   
        else
            unknown = true;
    }
    //                                              
    cout << "There were " << counter << " CDs found in this database."<< endl;
}

int main()
{//              
    assert (true) ;
/*                
                                                                                       
                                                                                        
                                                                                         
                                      
*/
    //                                                                  
    //          
    int counter = -1;
    Track new_track;

    ifstream infile;
    infile.open("Tracks.txt");

    string s;

    while (infile){
        getline(infile, new_track.artist);
        getline(infile, new_track.cd);
        infile >> new_track.year;
        infile >> new_track.track;
        getline(infile, s);
        getline(infile, new_track.title);
        getline(infile, new_track.tags);
        infile >> new_track.time;
        getline(infile, s);
        getline(infile, new_track.country);
        getline(infile, s);
        database.push_back(new_track);
        counter++;
    }

    TrackDisplay information = {true, true, true, true, true, true,true,true};

    int database_size = database.size();
    for (int i = 0; i < database_size; i++)
        show_track(database[i],information);

    cout << "We added " << counter << " tracks to the database." << endl;

    //       
    //                                 
    //       
    //                                  
    //       
    //                              
    //       
    //                      

	return 0;
}

