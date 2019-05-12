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

typedef vector<Track> MusicDB;              //                                                   

bool match (string sub, string source)
{//              
    assert (true);

/*                
                                                                                  
*/
    return source.find(sub) != string::npos ;
}

ostream& operator<< (ostream& out, const Length length)
{//              
    assert (length.seconds < 60 && length.minutes < 60);

    out << length.minutes << ":" << length.seconds;
    return out;

/*                
                                                                                          
*/
}

istream& operator>> (istream& in, Length& length)
{//              
    assert (true);

    char c;

    in >> length.minutes >> c >> length.seconds;
    return in;

/*                
                                                                                    
*/
}

Length operator+ (const Length& a, const Length& b)
{//              
    assert (0 <= a.minutes && 0 <= a.seconds && a.seconds < 60 && 0 <= b.minutes && 0 <= b.seconds && b.seconds < 60);

    Length totaal;

    int c = a.minutes + b.minutes;
    int d = a.seconds + b.seconds;

    if (d >= 60){
        d = d - 60;
        c++;
    }

    totaal = {c, d};
    return totaal;

/*                
                                 
*/
}

void show_track (Track track, TrackDisplay lt)
{//              
    assert (true);

    if (lt.showArtist){
        cout << track.artist << endl;
    }

    if (lt.showAlbum){
        cout << track.cd << endl;
    }

    if (lt.showYear){
        cout << track.year << endl;
    }

    if (lt.showTrack){
        cout << track.track << endl;
    }

    if (lt.showTitle){
        cout << track.title << endl;
    }

    if (lt.showTags){
        cout << track.tags << endl;
    }

    if (lt.showLength){
        cout << track.time << endl;
    }

    if (lt.showCountry){
        cout << track.country << endl;
    }

/*                
                                                                                         
*/
}

istream& operator>> (istream& in, Track& track)
{//              
    assert (true);
    string leeg;

    getline (in, track.artist);
    getline (in, track.cd);
    in >> track.year;
    in >> track.track;
    getline (in, leeg);
    getline (in, track.title);
    getline (in, track.tags);
    in >> track.time;
    getline (in, leeg);
    getline (in, track.country);

    return in;

/*                
                                                                                                                 
                                                          
*/
}

int match_tracks (MusicDB& tracks, string track, bool display)
{
    int j = 0;
    TrackDisplay lt;
    lt.showArtist = true;
	lt.showAlbum = true;
	lt.showYear = true;
	lt.showTrack = true;
	lt.showTitle = true;
	lt.showTags = true;
	lt.showLength = true;
	lt.showCountry = true;

    for (int i = 0; i < tracks.size(); i++){
        if (match (track, tracks[i].title)){
            j++;
            if (display){
                show_track(tracks[i], lt);
            }
        }
    }
    return j;
}

int match_artists (MusicDB& tracks, string artist, bool display)
{
    int j = 0;
    TrackDisplay lt;
    lt.showArtist = true;
	lt.showAlbum = false;
	lt.showYear = false;
	lt.showTrack = false;
	lt.showTitle = false;
	lt.showTags = false;
	lt.showLength = false;
	lt.showCountry = false;

    for (int i = 0; i < tracks.size(); i++){
       if (match (artist, tracks[i].artist)){
           if (display){
               show_track(tracks[i], lt);
           }
       }
    j++;
    }
    return j;
}

int match_cds (MusicDB& tracks, string artist, bool display)
{
    int j = 0;
    TrackDisplay lt;
    lt.showArtist = true;
	lt.showAlbum = true;
	lt.showYear = true;
	lt.showTrack = false;
	lt.showTitle = false;
	lt.showTags = false;
	lt.showLength = false;
	lt.showCountry = false;

	for (int i = 0; i < tracks.size(); i++){
       if (match (artist, tracks[i].artist)){
           if (display){
               show_track(tracks[i], lt);
           }
       }
    j++;
    }
    return j;
}

int number_of_cds (MusicDB& tracks)
{
    int j = 0;
    TrackDisplay lt;
    lt.showArtist = false;
	lt.showAlbum = true;
	lt.showYear = false;
	lt.showTrack = false;
	lt.showTitle = false;
	lt.showTags = false;
	lt.showLength = false;
	lt.showCountry = false;

/*                                      */

}

int main()
{
    MusicDB compleet;
    Track lijst;
    string leeg;

    ifstream myfile;
    myfile.open("Nummers.txt");
    if (myfile.is_open()){
        while (!myfile.eof()){
            myfile >> lijst;
            compleet.push_back(lijst);
            getline (myfile, leeg);
        }
    }
    cout << compleet.size();

    return 0;

/*                
                                                                                        
                                                                                           
*/

}

