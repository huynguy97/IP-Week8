#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cassert>

//                                                  

using namespace std;

struct Length
{
    int minutes;                            //                
    int seconds;                            //                  
};

struct Track
{
    string artist;                          //                             
    string cd;                              //             
    int    year;                            //                 
    int    track;                           //                 
    string title;                           //                
    string tags;                            //               
    Length time;                            //                 
    string country;                         //                 
};

struct TrackDisplay
{
    bool showArtist;                        //                      
    bool showAlbum;                         //                        
    bool showYear;                          //                    
    bool showTrack;                         //                        
    bool showTitle;                         //                           
    bool showTags;                          //                    
    bool showLength;                        //                            
    bool showCountry;                       //                       
};

bool match (string sub, string source)
{//             
    assert (true) ;
/*               
                                                                                               
*/
    return source.find(sub) != string::npos ;
}

ostream& operator<< (ostream& out, const Length lengte)
{//             
    assert (true) ;
/*               
                                                                                                   
*/
    if(lengte.minutes < 10){
        cout << "0";
    }
    cout << lengte.minutes << ":";
    if(lengte.seconds < 10){
        cout << "0";
    }
    cout << lengte.seconds;

}

istream& operator>> (istream& in, Length& lengte)
{//             
    assert (true) ;
/*               
                                                                                         
*/
    in >> lengte.minutes;
    in.ignore(1);
    in >> lengte.seconds;

}

Length operator+ (const Length& a, const Length& b)
{//             
    assert (0 <= a.minutes && 0 <= a.seconds && a.seconds < 60 && 0 <= b.minutes && 0 <= b.seconds && b.seconds < 60) ;
/*               
                                   
*/
    Length res;
    res.minutes = a.minutes + b.minutes;
    res.seconds = a.seconds + b.seconds;
    if (res.seconds >= 60){
        res.minutes++;
        res.seconds -= 60;
    }
    return res;
}

void show_track (const Track lied,const TrackDisplay lt)
{//             
    assert (true) ;
/*               
                                                                                                           
*/
    if (lt.showArtist){
        cout << lied.artist << "\n";
    }
    if (lt.showAlbum){
        cout << lied.cd << "\n";
    }
    if (lt.showYear){
        cout << lied.year << "\n";
    }
    if (lt.showTrack){
        cout << lied.track << "\n";
    }
    if (lt.showTitle){
        cout << lied.title << "\n";
    }
    if (lt.showTags){
        cout << lied.tags << "\n";
    }
    if (lt.showLength){
        cout << lied.time << "\n";
    }
    if (lt.showCountry){
        cout << lied.country << "\n";
    }
    cout << endl;
}

istream& operator>> (istream& in, Track& track)
{//             
    assert (true) ;
/*               
                                                                                                                     
                                                         
*/

    getline(in, track.artist);
    getline(in, track.cd);
    in >> track.year;
    in.ignore(1000,'\n');
    in >> track.track;
    in.ignore(1000,'\n');
    getline(in, track.title);
    getline(in, track.tags);
    in >> track.time;
    in.ignore(1000,'\n');
    getline(in, track.country);
    in.ignore(1000,'\n');
}

const int MAX_NR_OF_TRACKS = 5000;
typedef Track MusicDB [MAX_NR_OF_TRACKS];

int read_tracks(ifstream& file, MusicDB DB){
    //       
    assert(file.is_open());
    /*           
                                                                        
    */

    int count = 0;
    Track track;
    while(true){
        file >> track;
        if(file){
            DB[count] = track;
            count++;
        }
        else{
            cout << "Investigated " << count << " tracks.\n";
            return count;
        }
    }
}

void welcome_message(){
    cout << "What do you want?\n";
    cout << "(1) Enter a track title.\n";
    cout << "(2) Enter an artists name to count its number of tracks.\n";
    cout << "(3) Enter an artists name to search its cds.\n";
    cout << "(4) Count the number of cd's.\n";
    cout << "(5) Computes the total playing time of all numbers.\n";
    cout << "(6) Enter a track. Searches for every cd with a track that contains that title.\n";
    cout << "(7) Enter a tag. Searches every track that has that tag.\n";
    cout << "(8) Enter a cd title. Searches every artist that has a cd with that name and the total number of them.\n";
    cout << "(9) Enter a cd title. Displays all tracks of cds of that title.\n";
    cout << "(10) Terminate\n";
}

void search_track(const MusicDB DB, const int DBcount, const string title){
    //         
    assert(DBcount >=0);

    /*          
                                                                                             
    */

    TrackDisplay TD = {true, true, true, true, true, true, true, true};
    int count = 0;
    for( int j = 0; j<DBcount; j++){
        if(DB[j].title == title){
           show_track(DB[j], TD);
           count++;
        }
    }
    cout << "Counted " << count << " tracks titled " << title << ".\n";
}

void search_artist(const MusicDB DB, const int DBcount, const string artist){
    //         
    assert(DBcount >= 0);

    /*          
                                                      
    */
    bool found = false;
    int acount = 0;
    for(int i= 0; i<DBcount; i++){
        if(DB[i].artist == artist){
            found = true;
            acount++;
        }
        else if(found){
            break;
        }
    }
    cout << artist << " has " << acount << " tracks in the Database.\n";
}

void cds_artist(const MusicDB DB, const int DBcount, const string artist){
    //         
    assert(DBcount >= 0);

    /*          
                               
    */

    TrackDisplay TD = {true, true, true, false, false, false, false, false};
    int cdcount = 0;
    string cd = "";
    bool found = false;
    for(int i=0; i<DBcount; i++){
        if(DB[i].artist == artist && DB[i].cd != cd){
            cd = DB[i].cd;
            found = true;
            show_track(DB[i], TD);
            cdcount++;
        }
        else if(found && DB[i].artist != artist){
            break;
        }
    }
    cout << artist << " has " << cdcount << " cd's in this Database.\n";
}

void count_cds(const MusicDB DB, const int DBcount){
    //         
    assert(DBcount >= 0);
    /*          
                                                                               
    */

    string artist = "";
    string cd = "";
    int count = 0;
    for(int i=0; i<DBcount; i++){
        if(DB[i].cd != cd || DB[i].artist != artist){
            count++;
            cd = DB[i].cd;
            artist = DB[i].artist;
        }
    }
    cout << "The Database consists of " << count << " cd's.\n";
}

void total_time(const MusicDB DB, const int DBcount){
    //         
    assert(DBcount >= 0);
    /*          
                                                                             
    */

    Length total = DB[0].time;
    for(int i=1; i<DBcount; i++){
        total = total + DB[i].time;
    }
    cout << "The total playing time of the Database is " << total << endl;
}

void cd_track(const MusicDB DB, const int DBcount, const string title){
    //         
        assert(DBcount >= 0);
    /*          
                                                                                                                        
    */

    TrackDisplay TD = {true, true, true, false, false, false, false, false};
    string artist = "";
    string cd = "";
    int count = 0;

    for(int i=0; i<DBcount; i++){
        if(DB[i].title == title && (DB[i].artist != artist || DB[i].cd != cd)){
            artist = DB[i].artist;
            cd = DB[i].cd;
            count++;
            show_track(DB[i],TD);
        }
    }
    cout << "There are " << count << " cd's that contain a track with title " << title << ".\n";

}

void search_tag(const MusicDB DB, const int DBcount, const string tag){
    //         
        assert(DBcount >= 0);
        /*          
                                                                                                                                
        */

        TrackDisplay TD = {true, true, true, true, true, true, true, false};
        int count = 0;
        for(int i=0; i<DBcount; i++){
            if(DB[i].tags == tag){
                show_track(DB[i], TD);
                count++;
            }
        }
        cout << count << " tracks have the tag " << tag << ".\n";
}

void search_cd(const MusicDB DB, const int DBcount, const string cd){
    //         
        assert(DBcount >= 0);
        /*          
                                                                                                                   
        */

        TrackDisplay TD = {true, true, false, false, false, false, false, false};
        int count = 0;
        string artist = "";
        for(int i=0; i<DBcount; i++){
            if(DB[i].cd == cd && DB[i].artist != artist){
                artist = DB[i].artist;
                count++;
                show_track(DB[i], TD);
            }
        }
        cout << count << " cd's with title " << cd << " are found.\n";
}

void show_cd(const MusicDB DB, const int DBcount, const string cd){
    //         
        assert(DBcount >= 0);
        /*          
                                                                                                                                         
        */

        TrackDisplay TD = {true, true, true, true, true, true, true, true};
        TrackDisplay TD2 = {false, false, false, true, true, true, true, true};
        int count = 0;
        string artist = "";
        for(int i=0; i<DBcount; i++){
            if(DB[i].cd == cd){
                if(DB[i].artist == artist){
                  show_track(DB[i], TD2);
                }
                else{
                   artist = DB[i].artist;
                   count++;
                   show_track(DB[i],TD);
                }
            }
        }
        cout << count << " cd's with title " << cd << " are found.\n";
}

enum Command {track = 1, artist, cds, numbcds, time, cdtrack, tag, cdartist, trackcd, stop};

bool execution(const MusicDB DB, const int DBcount, const int input){
    //         
    assert(DBcount >=0 && 1 <= input && input <= 10);

    /*          
                                           
    */

    switch(static_cast<Command>(input)){
        case stop:{
            return false;
            break;
        }
        case track:{
            cin.ignore(1000,' ');
            string title;
            getline(cin, title);
            search_track(DB, DBcount, title);
            break;
        }
        case artist:{
            cin.ignore(1000,' ');
            string artist;
            getline(cin, artist);
            search_artist(DB, DBcount, artist);
            break;
        }
        case cds:{
            cin.ignore(1000, ' ');
            string artist;
            getline(cin, artist);
            cds_artist(DB, DBcount, artist);
            break;
        }
        case numbcds:{
            cin.ignore(1000,'\n');
            count_cds(DB, DBcount);
            break;
        }
        case time:{
            cin.ignore(1000,'\n');
            total_time(DB, DBcount);
            break;
        }
        case cdtrack:{
            cin.ignore(1000,' ');
            string title;
            getline(cin, title);
            cd_track(DB, DBcount, title);
            break;
        }
        case tag:{
            cin.ignore(1000,' ');
            string tag;
            getline(cin, tag);
            search_tag(DB, DBcount, tag);
            break;
        }
        case cdartist:{
            cin.ignore(1000,' ');
            string cd;
            getline(cin, cd);
            search_cd(DB, DBcount, cd);
            break;
        }
        case trackcd:{
            cin.ignore(1000,' ');
            string cd;
            getline(cin, cd);
            show_cd(DB, DBcount, cd);
            break;
        }
    }
    return true;
}

void IO_app(const MusicDB DB, const int DBcount){
    //       
    assert(DBcount >=0);
    /*           
                                            
    */

    bool cont = true;
    while (cont){
        welcome_message();
        int input;
        cin >> input;
        cont = execution(DB, DBcount, input);

    }
}

int main()
{//             
    assert (true) ;
/*               
                                                                                            
                                                                                               
                   
*/

   ifstream file;
   file.open("Nummers.txt");
   if(file){
    MusicDB DB;
    int DBcount = read_tracks(file, DB);
    IO_app(DB, DBcount);

   }
}

