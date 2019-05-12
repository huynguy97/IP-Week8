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

bool match (string sub, string source)
{
    //              
    assert (true) ;
    /*                
                                                                                      
    */
    return source.find(sub) != string::npos ;
}

ostream& operator<< (ostream& out, const Length length)
{
    //              
    assert (true) ;
    /*                
                                                                                              
    */
    out << length.minutes << ':' ;
    if (length.seconds < 10)
        out << '0' ;
    out << length.seconds;
    return out ;

}

istream& operator>> (istream& in, Length& length)
{
    //              
    assert (true) ;
    /*                
                                                                                        
    */
    char colon;
    in >> length.minutes >> colon >> length.seconds;
    return in;
}

Length operator+ (const Length& a, const Length& b)
{
    //              
    assert (0 <= a.minutes && 0 <= a.seconds && a.seconds < 60 && 0 <= b.minutes && 0 <= b.seconds && b.seconds < 60) ;
    /*                                            
                        
                                     
    */
    Length temp;
    if(a.seconds + b.seconds > 59)
    {
        temp.seconds = a.seconds + b.seconds - 60;

        temp.minutes += 1;
    }
    else
    {
        temp.seconds = a.seconds + b.seconds;
    }
    temp.minutes += a.minutes + b.minutes;
    return temp;
}

void show_track (Track track, TrackDisplay lt)
{
    //              
    assert (true) ;
    /*                
                                                                                             
    */
    if(lt.showArtist)
    {
        cout << track.artist << endl;
    }
    if(lt.showAlbum)
    {
        cout << track.cd << endl;
    }
    if(lt.showYear)
    {
        cout << track.year << endl;
    }
    if(lt.showTrack)
    {
        cout << track.track << endl;
    }
    if(lt.showTitle)
    {
        cout << track.title << endl;
    }
    if(lt.showTags)
    {
        cout << track.tags << endl;
    }
    if(lt.showLength)
    {
        cout << track.time << endl;
    }
    if(lt.showCountry)
    {
        cout << track.country << endl;
    }
    cout << endl;
}

istream& operator>> (istream& in, Track& track)
{
    //              
    assert (true) ;
    /*                
                                                                                                                     
                                                              
    */
    string dummy;
    getline(in,track.artist);       //       
    getline(in,track.cd);           //   
    in >> track.year ;              //     
    getline(in, dummy) ;            //                      
    in >> track.track ;             //         
    getline(in, dummy) ;            //                      
    getline(in,track.title);        //            
    getline(in,track.tags);         //           
    in >> track.time ;              //           
    getline(in, dummy) ;            //                      
    getline(in,track.country);      //        
    getline(in, dummy) ;            //                      
    return in ;
}

bool is_empty(std::ifstream& pFile)
{
    //              
    assert(true);
    /*               
                                       
    */
    return pFile.peek() == std::ifstream::traits_type::eof();
}

vector<Track> readFile(char* filename)
{
    //              
    assert(true);
    /*               
                                                 
    */
    vector<Track> track;
    Track temp;
    ifstream infile;
    infile.open(filename);
    if (!infile)
    {
        cout << "could not open '" << filename << "'." << endl;
        return track;
    }

    if(!is_empty(infile))
    {
        do
        {
            infile >> temp;
            track.push_back(temp);
        }
        while(infile);
    }
    return track;
}

int match_tracks (vector<Track>& tracks, string track, bool display)
{
    //              
    assert(true);
    /*               
                                                                           
    */
    int counter = 0;
    TrackDisplay displayer;
    displayer.showArtist = true;
    displayer.showAlbum = true;
    displayer.showYear = true;
    displayer.showTitle = true;
    displayer.showTags = true;
    displayer.showLength = true;
    displayer.showCountry = true;
    for(int i = 0; i < tracks.size(); i++)
    {
        if(match(track, tracks.at(i).title))
        {
            counter++;
            if(display)
            {
                show_track(tracks.at(i), displayer);
            }
        }
    }
    return counter;
}

int match_artists (vector<Track>& tracks, string artist, bool display)
{
    //              
    assert(true);
    /*               
                                                               
    */
    int counter = 0;
    TrackDisplay displayer;
    string newartist;
    displayer.showArtist = true;
    displayer.showAlbum = false;
    displayer.showYear = false;
    displayer.showTitle = false;
    displayer.showTags = false;
    displayer.showLength = false;
    displayer.showCountry = false;
    for(int i = 0; i < tracks.size(); i++)
    {
        if(match(artist, tracks.at(i).artist) && !tracks.at(i).artist.compare(newartist) == 0)
        {
            newartist = tracks.at(i).artist;
            counter++;
            if(display)
            {
                show_track(tracks.at(i), displayer);
            }
        }
    }
    return counter;
}

int match_cds (vector<Track>& tracks, string artist, bool display)
{
    //              
    assert(true);
    /*               
                                                                                 
    */
    int counter = 0;
    TrackDisplay displayer;
    string newcd;
    displayer.showArtist = false;
    displayer.showAlbum = true;
    displayer.showYear = true;
    displayer.showTitle = false;
    displayer.showTags = false;
    displayer.showLength = false;
    displayer.showCountry = false;
    for(int i = 0; i < tracks.size(); i++)
    {
        if(match(artist, tracks.at(i).artist) && !tracks.at(i).cd.compare(newcd) == 0)
        {
            newcd = tracks.at(i).cd;
            counter++;
            if(display)
            {
                show_track(tracks.at(i), displayer);
            }
        }
    }
    return counter;
}

int number_of_cds (vector<Track>& tracks)
{
    //              
    assert(true);
    /*               
                             
    */
    int counter = 1;
    string newcd = tracks.at(0).cd;
    for(int i = 0; i < tracks.size(); i++)
    {
        if(newcd.compare(tracks.at(i).cd) != 0)
        {
            counter++;
            newcd = tracks.at(i).cd;
        }
    }
    return counter;
}

void commandline(vector<Track> tracks)
{
    //              
    assert(true);
    /*               
                                                                                   
                  
                    
                 
         
         
    */
    string arguments;
    cout << "enter command" << endl;
    string input;
    cin >> input;
    while(input != "stop")
    {
        if(input == "#cds")
        {
            cout << "#total cd's:" << number_of_cds(tracks) << endl;
        }
        getchar();
        getline(cin, arguments);
        if(input == "track")
        {
            cout << "#tracks:" << match_tracks(tracks, arguments, true) << endl;
        }
        else if(input == "artist")
        {
            cout << "#artists:" <<match_artists(tracks, arguments, true) << endl;
        }
        else if(input == "cds")
        {
            cout << "#cd's" <<match_cds(tracks, arguments, true) << endl;
        }
        else cout << "invalid input." << endl;
        cin >> input;
    }
}

int main()
{
    //              
    assert (true) ;
    /*                
                                                                                           
                                                                                            
                                                                                             
                                          
    */
    vector<Track> tracks;
    tracks = readFile("Tracks.txt");
    commandline(tracks);
    return 0;
}

