//Header File Imports
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
#include<bits/stdc++.h>
#include<time.h>

    static int x;
    static int majorCycleNumber;
    static int sensorMinorCycleNumnber;

using namespace std;
   
   const int SENSOR_LOOP_COUNT_MAX = 2;
   const int FUSION_LOOP_COUNT_MAX = 4;
   //const int SENSOR_MINOR_CYCLE_MAX = 4;
   //
   const int SENSOR_FUSION_UPDATE_COUNTER_MAX = 10;
   const int PLANAR_COORDINATES = 2;
   static int SENSOR_FUSION_UPDATE_COUNTER = 0;
   static bool entered_once = false;


class DataBase {
    protected:
    //Data members
    int arrCamPos[2];
    int sensorPosArray [1000];
    int arrIndex;
    int numberOfSensorsInUse;
    int ret_val =0;
    public:
    DataBase(){
        for(int k=0;k<1000;k++) {
            sensorPosArray[k] = 0;
        }
        numberOfSensorsInUse = 0;
        arrIndex = 0;

    }
    void dbupdateAckCamera(int p, int q) {
        //Func Defintion
        if(arrIndex==1000){arrIndex = 0;}
        // cout << "Array Index in camera before upd is : "<< arrIndex << endl;
        sensorPosArray[arrIndex++] = p;
        // cout << "Array Index in camera is : "<< arrIndex << endl;
        sensorPosArray[arrIndex++] = q;
        // cout << "Array Index in camera after allupd is : "<< arrIndex << endl;
        
    }
    void dbupdateAckLidar(int g, int h) {
        //Func Drefintion
        // arrIndex++;
        if(arrIndex==1000){arrIndex = 0;}   
        // cout << "Array Index in lidar before upd is : "<< arrIndex << endl;  
        sensorPosArray[arrIndex++] = g;
        // cout << "Array Index in Lidar is : "<< arrIndex << endl;
        sensorPosArray[arrIndex++] = h;
        // cout << "Array Index in Lidar after allupd is : "<< arrIndex << endl;

    }
    void dbupdateAckAcoustic(int s, int t) {
        //Func Definition
        // arrIndex++;
        if(arrIndex==1000){arrIndex = 0;}    
       // cout << "Array Index in Acoustic before upd is : "<< arrIndex << endl;            
        sensorPosArray[arrIndex++] = s;
        sensorPosArray[arrIndex++] = t;
      //  cout << "Array Index in Acoustic after allupd is : "<< arrIndex << endl;
        //cout << "Array Index in Acoustic is : "<< arrIndex << endl;
        // cout << "Array Index in Acoustic is : "<< arrIndex << endl;
    }
    void dbupdateNumberOfSensors(int numberOfSensors) {
        numberOfSensorsInUse = numberOfSensors;
    }
    int getCamera_X_Position(){
        //Func Defintion
        
        int curr_x_pos_camera_index = 0;
        int offset_to_move = 0;
        if (numberOfSensorsInUse == 3) {

         //  cout << "While retrieving, Array Index for camera x pos is : " << arrIndex << endl;
           offset_to_move = arrIndex -  (numberOfSensorsInUse * PLANAR_COORDINATES);
           curr_x_pos_camera_index =  arrIndex + offset_to_move;
           cout<<"getCamera_X_Position"<<endl;
        } else {
           cout<<"getCamera_X_Position - else"<<endl;
        }
      //  cout << " Retv val X from camera is : " << sensorPosArray[curr_x_pos_camera_index] << endl;
        ret_val = sensorPosArray[curr_x_pos_camera_index];
        return ret_val;
    }
      int getCamera_Y_Position(){
        //Func Defintion
        
       int curr_y_pos_camera_index = 0;
       int offset_to_move = 0;

        if (numberOfSensorsInUse == 3) {
         //  cout << "While retrieving, Array Index for camera y pos is : " << arrIndex << endl;
           offset_to_move =(arrIndex - (numberOfSensorsInUse * PLANAR_COORDINATES)) + 1 ;
           curr_y_pos_camera_index =  arrIndex + offset_to_move;
           
           cout<<"getCamera_Y_Position"<<endl;
        } else {
           cout<<"getCamera_Y_Position - else"<<endl;
        }
       // cout << " Retv val Y from camera is : " << sensorPosArray[curr_y_pos_camera_index] << endl;
        return sensorPosArray[curr_y_pos_camera_index];        
    }

    int getLidar_X_Position() {
        //Func Definition
                int curr_x_pos_lidar_index = 0;

        if (numberOfSensorsInUse == 3) {
           curr_x_pos_lidar_index =  arrIndex -  ((numberOfSensorsInUse * PLANAR_COORDINATES ) - 3);
           cout<<"getLidar_X_Position"<<endl;
        } else {
           cout<<"getLidar_X_Position - else"<<endl;
        }
        return sensorPosArray[curr_x_pos_lidar_index];
    }

    int getLidar_Y_Position(){
        //Func Defintion
        
        int curr_y_pos_lidar_index = 0;

        if (numberOfSensorsInUse == 3) {
           curr_y_pos_lidar_index =  arrIndex -  ((numberOfSensorsInUse * PLANAR_COORDINATES ) - 4);
           cout<<"getLidar_Y_Position"<<endl;
        } else {
           cout<<"getLidar_Y_Position - else"<<endl;
        }
        return sensorPosArray[curr_y_pos_lidar_index];
    }

    int getAcoustic_X_Position() {
        //Func Definition
        int curr_x_pos_acoustic_index = 0;

        if (numberOfSensorsInUse == 3) {
           curr_x_pos_acoustic_index =  arrIndex -  ((numberOfSensorsInUse * PLANAR_COORDINATES ) -5 );
           cout<<"getAcoustic_X_Position"<<endl;
        } else {
           cout<<"getAcoustic_X_Position - else"<<endl;
        }
        return sensorPosArray[curr_x_pos_acoustic_index];
    }

    int getAcoustic_Y_Position(){
               //Func Defintion
        
       int curr_y_pos_acoustic_index = 0;

        if (numberOfSensorsInUse == 3) {
           curr_y_pos_acoustic_index =  arrIndex - ((numberOfSensorsInUse * PLANAR_COORDINATES ) -6);
           cout<<"getAcoustic_Y_Position"<<endl;
        } else {
           cout<<"getAcoustic_Y_Position - else"<<endl;
        }
        return sensorPosArray[curr_y_pos_acoustic_index];
    }
        
};

class Sensor {
    public:
    int sensorCameraData;
    int sensorLidarData;
    int sensorAcousticData;
    //Data Members
    //Functions
};
class CameraSensor: public Sensor {
    protected:
    //data members
    int x1, y1;
    DataBase *dbforCamUpd;
    public:

    CameraSensor(int a, int b) {x1 = a; y1 = b;}

    void generatePosition() {

        int delta = 0;
        //Func Definiton
        cout<<"Camera sensor x Position  before update: "<<x1<<'\t';
        cout<<"Camera sensor y Position before update: "<<y1<<endl;
        // srand(time(0));

        delta =  (rand() % 10) + 1;      

        x1 = SENSOR_FUSION_UPDATE_COUNTER + delta;

        delta =  (rand() % 10) + 1;

        y1 = SENSOR_FUSION_UPDATE_COUNTER + delta;
        // x1 = rand();
        // y1 = rand();
        
       }

    void run() {
        //Func Defintion
        generatePosition();
        updateCameraPosition(*dbforCamUpd);
    }
    
    void updateCameraPosition(DataBase & db) {
        //Func Defintion
        db.dbupdateAckCamera(x1, y1);
    }

    void connectDatabase (DataBase &db)
    {
         dbforCamUpd = &db;
    }
};

class LidarSensor: public Sensor{
    protected:
    //Data Members
    int x2,y2;
    DataBase *dbForLidarUpd;

    public:
    LidarSensor(int m, int n) {x2 = m; y2 = n;}
    void generatePosition() {
        //Func Definition
        int delta = 0;

        cout<<"Lidar sensor x Position  before update: "<<x2<<'\t';
        cout<<"Lidar sensor y Position before update: "<<y2<<endl;
        delta =  (rand() % 10) + 1;      

        x2 = SENSOR_FUSION_UPDATE_COUNTER + delta;

        delta =  (rand() % 10) + 1;

        y2 = SENSOR_FUSION_UPDATE_COUNTER + delta;
    }

    void run() {
        //Func Defintion
        generatePosition();
        updateLidarPosition(*dbForLidarUpd);
    }

    void updateLidarPosition(DataBase & db) {
        //Func Definition
        db.dbupdateAckLidar(x2, y2);
    }
        void connectDatabase (DataBase &dbl)
    {
         dbForLidarUpd = &dbl;
    }

};
class AcousticSensor: public Sensor{
    protected:
    //Data Members
    int x3,y3;
    DataBase *dbForAcousUpd;

    public:
    AcousticSensor(int e, int f) {x3 = e; y3 = f;}
    void generatePosition() {
        //Func Definition
        int delta = 0;

        cout<<"Acoustic sensor x Position  before update: "<<x3<<'\t';
        cout<<"Acoustic sensor y Position before update: "<<y3<<endl;
        delta =  (rand() % 10) + 1;      

        x3 = SENSOR_FUSION_UPDATE_COUNTER + delta;

        delta =  (rand() % 10) + 1;

        y3 = SENSOR_FUSION_UPDATE_COUNTER + delta;
    }

    void run() {
        //Func Defintion
        generatePosition();
        updateAcousticPosition(*dbForAcousUpd);
    }

    void updateAcousticPosition(DataBase & db) {
        //Func Definition
        db.dbupdateAckAcoustic(x3, y3);
    }

    void connectDatabase (DataBase &dba)
    {
         dbForAcousUpd = &dba;
    }
};

class Fusion {
    protected:
    //Data members
    int x1c, y1c, x1l, y1l, x1a, y1a;
    float fused_x_pos;
    float fused_y_pos;
    public:
    void fuseAlgo1(DataBase & dbOfSensorRdgs ) {
        //Func Definition
      // dbOfSensorRdgs->getCamera_X_Position();
      cout<<"Inside Fuse Algo"<<"\n";
      x1c = dbOfSensorRdgs.getCamera_X_Position();

      cout<<"Retrived value of x1c by DB: "<<x1c<<endl;

      y1c = dbOfSensorRdgs.getCamera_Y_Position();
      cout<<"Retrived value of y1c by DB: "<<y1c<<endl;

      x1l = dbOfSensorRdgs.getLidar_X_Position();

      cout<<"Retrived value of x1l by DB: "<<x1l<<endl;

      y1l = dbOfSensorRdgs.getLidar_Y_Position();
      cout<<"Retrived value of y1l by DB: "<<y1l<<endl;

      x1a = dbOfSensorRdgs.getAcoustic_X_Position();

      cout<<"Retrived value of x1a by DB: "<<x1a<<endl;

      y1a = dbOfSensorRdgs.getAcoustic_Y_Position();
      cout<<"Retrived value of y1a by DB: "<<y1a<<endl;

      // SIMPLE FUSION
      fused_x_pos = 0;
      fused_x_pos  = (x1c + x1l + x1a)/3.0;

      fused_y_pos = 0;
      fused_y_pos  = (y1c + y1l + y1a)/3.0;

    }
    void displayFusedPosition(){
        //Func Defintion
        cout<<"Fused X Position: "<<fused_x_pos<<"\t";
        cout<<"Fused Y Position: "<<fused_y_pos<<"\t";
        cout << endl;
        cout<<"\n";
    }
};

class Controller {
    public:

    protected:
    //data members
    CameraSensor *_theCameraSensor;
    LidarSensor *_theLidarSensor;
    AcousticSensor *_theAcousticSensor;
    DataBase *_theDatabase;
    Fusion *_theFusion;
    int numberOfSensorsUsed;

    public:
    Controller(CameraSensor &cs, LidarSensor &ls, AcousticSensor &acs, DataBase &db, Fusion &fn, int nos) {
        
        _theCameraSensor = &cs;
        _theLidarSensor = &ls;
        _theAcousticSensor = &acs;
        _theDatabase = &db;
        _theFusion = &fn;
       //this->init();
       numberOfSensorsUsed = nos;
       //

    }
    void init(){
        //Func Definition
        // *_theCameraSensor = new 
         x = 0;
         //sensorMinorCycleNumber = 0;
         //majorCycleNumber = 0; 
         //

         //
        _theDatabase->dbupdateNumberOfSensors(numberOfSensorsUsed);
        _theCameraSensor->connectDatabase(*_theDatabase);
        _theLidarSensor->connectDatabase(*_theDatabase);
        _theAcousticSensor->connectDatabase(*_theDatabase);

        srand(time(0));
    }
    virtual void activate() {
        //Func Definiton
//Scheduler to run the program continuously

        cout << "Starting to activate ......"<<"\n";
       while(x <= 2) {
           while(SENSOR_FUSION_UPDATE_COUNTER < SENSOR_FUSION_UPDATE_COUNTER_MAX) {
               // if((SENSOR_FUSION_UPDATE_COUNTER == 4) || (SENSOR_FUSION_UPDATE_COUNTER == 8)) { entered_once = true;}
              // cout << "SENSOR_FUSION_UPDATE_COUNTER VAL is :" << SENSOR_FUSION_UPDATE_COUNTER<<endl<<endl;
               if( (SENSOR_FUSION_UPDATE_COUNTER == 0) || 
                   (SENSOR_FUSION_UPDATE_COUNTER == 2) || 
                   (SENSOR_FUSION_UPDATE_COUNTER == 4) ||
                   (SENSOR_FUSION_UPDATE_COUNTER == 6) ||
                   (SENSOR_FUSION_UPDATE_COUNTER == 8) )
                    {
                   cout<<"Invoking sensors......."<<endl;
                  _theCameraSensor->run();
                  _theLidarSensor->run();
                  _theAcousticSensor->run();                   
               }
               if ( (SENSOR_FUSION_UPDATE_COUNTER == 4) ||
                    (SENSOR_FUSION_UPDATE_COUNTER == 8) ) 
                   {
                  cout << "Invoking Fusion Algo ......"<<"\n";
                 _theFusion->fuseAlgo1(*_theDatabase);
                 _theFusion->displayFusedPosition();
                 entered_once = false;
                }          
                SENSOR_FUSION_UPDATE_COUNTER++;
               } 
               SENSOR_FUSION_UPDATE_COUNTER = 0;
               x++;
           }
       }
    
};



int main() {
//Objects instantiated

    CameraSensor camsnsr(0,0);
     
    LidarSensor lidsnsr(0,0);

    AcousticSensor acousnsr(0,0);

    DataBase db;

    Fusion fusionobj;

    int numberOfSensors = 3;

    Controller ctrlr(camsnsr, lidsnsr, acousnsr, db, fusionobj,numberOfSensors);

    ctrlr.init();

    ctrlr.activate();
   



}
