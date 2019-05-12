#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

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
    if (length.seconds >= 0 && length.seconds < 10)
    {
        out<<length.minutes << ":0" << length.seconds;
    }
    else
    {
        out << length.minutes << ":" << length.seconds;
    }
    return out;

}

istream& operator>> (istream& in, Length& length)
{//              
    assert (true) ;
/*                
                                                                                    
*/
    in >> length.minutes;
    in.ignore(1); //            
    in >> length.seconds;
    return in;
}

Length operator+ (const Length& a, const Length& b)
{//              
    assert (0 <= a.minutes && 0 <= a.seconds && a.seconds < 60 && 0 <= b.minutes && 0 <= b.seconds && b.seconds < 60) ;
/*                
                                 
*/
    Length total = {};
    if (a.seconds + b.seconds > 59)
    {
        total.minutes = 1;
        total.seconds = a.seconds + b.seconds - 60;
    }
    else
    {
        total.seconds = a.seconds + b.seconds;
    }

    total.minutes = total.minutes + a.minutes + b.minutes;

     return total = {total.minutes, total.seconds};

}

void show_track (Track track, TrackDisplay lt)
{//              
    assert (true) ;
/*                
                                                                                         
*/
    if (lt.showArtist){
        cout << "Artist: \t" << track.artist << endl;
    }
    if (lt.showAlbum){
        cout << "Album: \t\t" << track.cd << endl;
    }
    if (lt.showYear){
        cout << "Year: \t\t" << track.year << endl;
    }
    if (lt.showTrack){
        cout << "TrackNumber: \t" << track.track << endl;
    }
    if (lt.showTitle){
        cout << "TrackTitle: \t" << track.title << endl;
    }
    if (lt.showTags){
        cout << "Tags: \t\t" << track.tags << endl;
    }
    if (lt.showLength){
        cout << "Length: \t" << track.time << endl;
    }
    if (lt.showCountry){
        cout << "Country: \t" << track.country << endl;
    }
    cout << endl;
}

istream& operator>> (istream& in, Track& track)
{//              
    assert (true) ;
/*                
                                                                                                                 
                                                          
*/
        string dummy = "";

        getline(in, track.artist);
        getline (in, track.cd);
        in >> track.year;
        getline(in, dummy); //                   
        in >> track.track;
        getline(in, dummy); //                   
        getline (in, track.title);
        getline (in, track.tags);
        in >> track.time;
        getline(in, dummy); //                   
        getline (in, track.country);
        getline(in, dummy); //                          

        return in;

}

int vSize (vector<Track>& v)
{
    //              
    assert(true);
    //                                                              
    return static_cast<int>(v.size());
}

int match_tracks (vector<Track>& tracks, string track, bool display)
{
    //             
    assert(vSize(tracks) > 0);
    //                                                                                                                                                                     

    int matches = 0;
    int vecSize = vSize(tracks);
    TrackDisplay td = {true,true,true,true,true,true,true,true};

    for (int i = 0; i < vecSize; i++){
        if (match(track, tracks[i].title))
        {
            matches++;
            if (display){
                show_track(tracks[i],td);
            }
        }
    }

    return matches;
}

int svSize (vector<string>& v)
{
    //              
    assert(true);
    //                                                              
    return static_cast<int>(v.size());
}

int match_artists (vector<Track>& tracks, string artist, bool display)
{
    //             
    assert(vSize(tracks) > 0);
    //                                                                                                                                                    
    //                                                                                         

    int vecSize = vSize(tracks);
    TrackDisplay td = {};
    td.showArtist = true;

    vector<string> foundArtists;

    for (int i = 0; i < vecSize; i++){
        if (match(artist, tracks[i].artist))
        {
            int currFA = svSize(foundArtists);
            bool foundPrior = false;

            for (int j = 0; j < currFA; j++){
                if (tracks[i].artist == foundArtists[j]){
                    foundPrior = true;
                }
            }

            if (!foundPrior){
                foundArtists.push_back(tracks[i].artist);
                if (display){
                    show_track(tracks[i], td);
                }
            }
        }
    }

    return svSize(foundArtists);

}

int match_cds (vector<Track>& tracks, string artist, bool display)
{
    //             
    assert(vSize(tracks) > 0);
    //                                                                                                                                                 
    //                                                                                   

    int vecSize = vSize(tracks);
    TrackDisplay td = {};
    td.showArtist = true;
    td.showAlbum = true;
    td.showYear = true;

    vector<string> foundCDs;

    for (int i = 0; i < vecSize; i++){
        if (match(artist, tracks[i].artist))
        {
            int currFCD = svSize(foundCDs);
            bool foundPrior = false;

            for (int j = 0; j < currFCD; j++){
                if (tracks[i].cd == foundCDs[j]){
                    foundPrior = true;
                }
            }

            if (!foundPrior){
                foundCDs.push_back(tracks[i].cd);
                if (display){
                    show_track(tracks[i], td);
                }
            }
        }
    }

    return svSize(foundCDs);

}

int number_of_cds (vector<Track>& tracks)
{
    //             
    assert(vSize(tracks) > 0);
    //                                                                                        

    int vecSize = vSize(tracks);

    vector<string> CDList;

    for (int i = 0; i < vecSize; i++){

        int currFound = svSize(CDList);
        bool found = false;

        for (int j = 0; j < currFound; j++){
            if (tracks[i].cd == CDList[j]){
                found = true;
            }
        }

        if (!found){
            CDList.push_back(tracks[i].cd);
        }
    }

    return svSize(CDList);
}

int main()
{//              
    assert (true) ;
/*                
                                                                                       
                                                                                        
                                                                                         
                                      
*/

    cout << "please enter file name" << endl;
    string fileName = "";
    getline(cin, fileName);
    ifstream file(fileName.c_str());
    if (!file.is_open()){
        cout << "Could not open file" << endl;
        return 1;
    }

    TrackDisplay td = {true,true,true,true,true,true,true,true};

    vector<Track> trackDatabase;

    while (file)
    {
        Track track = {};
        file >> track;
        if (track.title != ""){ //                                                   
            trackDatabase.push_back(track);
            show_track(track, td);
        }
    }

    cout << "Total number of tracks read: " << vSize(trackDatabase) << endl << endl;

    cout << "====================== Functions on Test DB =======================" << endl;

    cout << "Match traks 'el' with output: " << endl;
    cout << "Matches found: " << match_tracks(testDB, "el", true) << endl;
    cout << endl << "===========================" << endl;

    cout << "Match artists 'el' with output: " << endl;
    cout << "Matches found: " << match_artists(testDB, "el", true) << endl;
    cout << endl << "===========================" << endl;

    cout << "Match CDs 'el' with output: " << endl;
    cout << "Matches found: " << match_cds(testDB, "el", true) << endl;
    cout << endl << "===========================" << endl;

    cout << "Number of CDs function: " << endl;
    cout << "Number of CDs: " << number_of_cds(testDB) << endl;

	return 0;
}

