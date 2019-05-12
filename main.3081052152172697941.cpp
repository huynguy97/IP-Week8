//                                                                     
//                                                                            
//                          
//                       
#include <iostream>
#include <iomanip>  //                                               
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

struct Length {
	unsigned int minutes;	//              
	unsigned int seconds;	//                
};

struct Track {
	string artist;  //              
	string cd;      //        
	int    year;    //                             
	int    track;		//            
	string title;   //           
	string tags;    //    
	Length time;		//            
	string country; //                            
};

struct TrackDisplay {
	bool showArtist;	//                            
	bool showAlbum;		//                      
	bool showYear;		//                                
	bool showTrack;		//                          
	bool showTitle;		//                         
	bool showTags;    //                  
	bool showLength;	//                          
	bool showCountry; //                                     
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
//                                 
class Length_input_error    {};
class Length_output_error   {};
class Length_addition_error {};

bool match(string substring, string string) {
  //             
  assert(true);
  //               
  //                                                        
  //                     
  return string.find(substring) != string::npos;
}

ostream& operator<<(ostream& out, const Length length) {
  //             
  //                                                 
  //                                                                                           
  //                        
  if (length.minutes < 0 || length.seconds < 0 || length.seconds > 59) throw Length_output_error{};
  //               
  //                                                                         
  //               
  return (out << length.minutes<<':'<< setfill('0') << setw(2) << length.seconds);
}

istream& operator>> (istream& in, Length& length) {
  //             
  assert(true); //                              
  //                                                                                 
  //                                                            
  char colon = ':';
  in>>length.minutes>>colon>>length.seconds;
  if (length.minutes < 0 || length.seconds < 0 || length.seconds > 59) throw Length_input_error{};
  return(in);
  //              
  //                                                                                
}

Length operator+ (const Length& a, const Length& b) {
  //            
  if (0 > a.minutes || 0 > a.seconds || a.seconds > 59 || 0 > b.minutes || 0 > b.seconds || b.seconds > 59) throw Length_addition_error{};
  //                                        
  unsigned int seconds = a.minutes * 60 + b.minutes * 60 + a.seconds + b.seconds;
  return {(seconds / 60),(seconds %  60)};
  //               
  //                             
}

void show_track (Track track, TrackDisplay td) {
  //               
  assert(true);
  if (td.showArtist)  cout<<"Artist      : "<<track.artist <<endl; //                        
  if (td.showAlbum)   cout<<"Album       : "<<track.cd     <<endl; //                       
  if (td.showYear)    cout<<"Year        : "<<track.year   <<endl; //               
  if (td.showTrack)   cout<<"Track       : "<<track.track  <<endl; //                       
  if (td.showTitle)   cout<<"Title       : "<<track.title  <<endl; //                
  if (td.showTags)    cout<<"Tags        : "<<track.tags   <<endl; //               
  if (td.showLength)  cout<<"Length      : "<<track.time   <<endl; //                 
  if (td.showCountry) cout<<"Country/ies : "<<track.country<<endl; //                                    
  cout<<endl;                                                      //                                               
  //               
  //                                                                                     
}

istream& operator>> (istream& in, Track& track) {   //             
  //             
  assert(true);
  string discard = "";
  getline(in, track.artist);  //                          
  getline(in, track.cd);      //                        
  in >> track.year;           //                 
  getline(in, discard);       //                 
  in >> track.track;          //                         
  getline(in, discard);       //                 
  getline(in, track.title);   //                  
  getline(in, track.tags);    //                 
  in >> track.time;           //                 
  getline(in, discard);       //                 
  getline(in, track.country); //                 
  getline(in, discard);       //                                                
  return in;
  //               
  //                                                        
  //                                                     
  //                                                      
  //                                                             
}

int match_tracks(vector<Track>& tracks, string title, bool display) {
  //             
  assert(true);
  unsigned int count = 0;
  for (Track track : tracks) {
    if (match(title, track.title)) {
      if (display)
        show_track(track, {true, true, true, true, true, true, true, true});
      count++;
    }
  }
  //               
  //                                                                         
  //                                                                       
  return count;
}

int cd_q(vector<Track>& tracks, string track_q, bool display) {
  //             
  assert(true);
  unsigned int count = 0;
  string previous_cd = "";
  for (Track track : tracks) {
    if (match(track_q, track.title) && track.title != previous_cd) {
      previous_cd = track.title;
      if (display)
        show_track(track, {true, true, true, false, false, false, false, false});
      count++;
    }
  }
  //               
  //                                                                                                
  return count;
}

int match_artist(vector<Track>& tracks, string artist, bool display) {
  //             
  assert(true);
  unsigned int count = 0;
  string previous_artist = "";
  for (Track track : tracks) {
    if (match(artist, track.artist) && track.artist != previous_artist) {
      //          
      previous_artist = track.artist;
      if (display)
        show_track(track, {true, false, false, false, false, false, false, false});
      count++;
    }
  }
  //               
  //                                                                                
  //                                                                       
  return count;
}

int artist_q(vector<Track>& tracks, string cd, bool display) {
  //             
  assert(true);
  unsigned int count = 0;
  string previous_cd = "";
  for (Track track : tracks) {
    if (match(cd, track.artist) && track.artist != previous_cd) {
      //          
      previous_cd = track.cd;
      if (display)
        show_track(track, {true, true, false, false, false, false, false, false});
      count++;
    }
  }
  //               
  //                                                                                               
  return count;
}

int match_cds(vector<Track>& tracks, string artist, bool display) {
  //             
  assert(true);
  unsigned int count = 0;
  string previous_artist = "";
  for (Track track : tracks) {
    if (match(artist, track.artist) && track.artist != previous_artist) {
      //          
      previous_artist = track.artist;
      if (display)
        show_track(track, {true, true, true, false, false, false, false, false});
      count++;
    }
  }
  //               
  //                                                                           
  //                                                                       
  return count;
}

int number_of_cds(vector<Track>& tracks) {
  //                                                             
  //                                             
  unsigned int count = 0;
  string cd    = "";
  for (Track track : tracks) {
    if (! (cd == track.cd)) {
      cd = track.cd;
      count++;
    }
  }
  return count;
  //              
  //                                                                           
}

void read_file(vector<Track>& database) {
  database.clear();
  ifstream file;
  string file_path = "Tracks.txt";
  unsigned int count = 0;
  cout<<"FILE PATH: "<<file_path;
  file.open(file_path);
  if (file.is_open()) {
    cout<<"\nYOU ENTERED A CORRECT FILE PATH!\nNow reading file...\n";
    for (Track track; file>>track;) {
      cout<<"Reading track...\n";
      database.push_back(track);
      show_track(track, {true, true, true, true, true, true, true, true});
      count++;
    }
  }
  cout<<"added "<<count<<" tracks to the database.\n";
  //              
  //                                                                                     
}

void assignment_test() {
  //                 
  cout<<"*** TESTING PART ONE ***\n";
  vector<Length> lengths = {{42,42}, {0,0}, {3,21}, {3,14}};
  for (Length i : lengths) {
    for (Length j : lengths)
      cout<<i<<"\t+\t"<<j<<"\t=\t"<<i+j<<endl;
  }

  //                 
  cout<<"*** TESTING PART TWO ***\n";
  for (Track track : testDB)
    show_track(track, {true, true, true, true, true, true, true, true});

  //                   
  cout<<"*** TESTING PART THREE ***\n";
  cout<<"*** TESTING match_tracks() ***\n";
  cout<<"In testDB there are "<<match_tracks(testDB, "el", false)<<" tracks that contain the string \"el\":\n\n";
  match_tracks(testDB, "el", true);
  cout<<"*** TESTING match_artists() ***\n";
  cout<<"In testDB there are "<<match_artist(testDB, "el", false)<<" artists that contain the string \"el\":\n\n";
  match_artist(testDB, "el", true);
  cout<<"*** TESTING match_cds() ***\n";
  cout<<"In testDB there are "<<match_cds(testDB, "el", false)<<" cds that are from an artist, whose name contains the string \"el\":\n\n";
  match_cds(testDB, "el", true);
  cout<<"*** TESTING number_of_cds() ***\n";
  cout<<number_of_cds(testDB)<<endl;

  //                  
  cout<<"*** TESTING PART FOUR ***\n";
  vector<Track> database;
  //                    
  //             
  //                                                
}

void runningtime(vector<Track>& tracks, string cd){
  //             
  assert(true);
  unsigned int total_time = 0;
  for (Track track : tracks) {
    if (match(cd, track.cd)) {
      show_track(track, {true, true, false, false, false, false, false, false});
      total_time += track.time.minutes * 60 + track.time.seconds;
    }
  }

  //                                         
  //                             
  //                                       
  //                           
  //                                       
  //                           
  unsigned int minutes = total_time % 60;
  total_time -= minutes * 60;
  cout<<"The total runningtime of all cd's matching the query "
      <<cd<<" is "<<minutes<<':'<<total_time<<".\n";
  //               
  //                                                     
}

void time(vector<Track>& tracks){
  //             
  assert(true);
  unsigned int total_time = 0;
  for (Track track : tracks) {
      total_time += track.time.minutes * 60 + track.time.seconds;
  }

  unsigned int weeks = total_time % 604800;
  total_time -= weeks * 604800;
  unsigned int days = total_time % 86400;
  total_time -= days * 86400;
  unsigned int hours = total_time % 3600;
  total_time -= hours * 3600;
  unsigned int minutes = total_time % 60;
  total_time -= minutes * 60;
  cout<<"The total runningtime of all tracks in the database is: "
      <<weeks<<" weeks, "
      <<days<<" days, "
      <<hours<<" hours and "
      <<minutes<<':'<<total_time<<"!\n";
  //                                                                       
  //                                                           
}

int year(vector<Track>& tracks, int year) {
  //             
  assert(true);
  unsigned int count = 0;
  string previous_cd = "";
  for (Track track : tracks) {
    if (track.year == year && previous_cd != track.cd) {
      previous_cd = track.cd;
      show_track(track, {true, true, false, false, false, false, false, false});
      count++;
    }
  }
  //               
  //                                                                         
  return count;
}

int main() {
  //             
  assert(true);
  //               
  //                                                                                   
  //                                                                                    
  //                                                                                     
  //                                  

  //                                    
  //                                                 
  vector<Track> database;
  //                                                          
  string query = "";

  //          
  for(string sub_program; cin>>sub_program;) {
    if (sub_program == "assignment-test") {
      //                                                      
      assignment_test();
      //                                                                     
      //                                                                            
    }  else if (sub_program == "track") {
      cin>>query;
      cout<<"found:\n"<<match_tracks(database, query, true)<<" tracks.\n";
    } else if (sub_program == "artist") {
      cin>>query;
      cout<<"found:\n"<<match_artist(database, query, true)<<" artists.\n";
    } else if (sub_program == "cds") {
      cin>>query;
      cout<<"found:\n"<<match_cds(database, query, true)<<" cds.\n";
    } else if (sub_program == "#cds") {
      cin>>query;
      cout<<"There are "<<number_of_cds(database)<<" cds.\n";
    } else if (sub_program == "cd?") {
      cin>>query;
      cout<<"found:\n"<<cd_q(database, query, true)<<" cds.\n";
    } else if (sub_program == "artist?") {
      cin>>query;
      cout<<"found:\n"<<artist_q(database, query, true)<<" artists.\n";
    } else if (sub_program == "runningtime") {
      cin>>query;
      runningtime(database, query);
    } else if (sub_program == "time") {
      time(database);
    } else if (sub_program == "year") {
      int y = 0;
      cin>>y;
      year(database, y);
    } else if (sub_program == "read") {
      read_file(database);
    } else if (sub_program == "stop" || sub_program == "q") {
      return 0;
    } else {
      cerr<<sub_program<<" IS NOT A SUBPROGRAM: PLEASE ENTER ONE FROM THE SPECIFICATION!\n";}
  }
}

//                                                                                   

