//Bradley Manning 8/2017



#ifndef CherenkovDetectorConstruction_h
#define CherenkovDetectorConstruction_h 1

#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"

class CherenkovDetectorConstruction : public G4VUserDetectorConstruction
{
public:
  CherenkovDetectorConstruction();
  ~CherenkovDetectorConstruction();

  
public:
  G4VPhysicalVolume* Construct();

  G4LogicalVolume* GetScoringVolume(int a) const {
    if (a == 1)
      return fScoringVolume;
    else
      return fScoringVolume2;
  }
protected:
  G4LogicalVolume* fScoringVolume;
  G4LogicalVolume* fScoringVolume2; 
private:
  G4double scintillatorBar_height;
  G4double scintillatorBar_width;
  G4double scintillatorBar_length;

  G4double tank_innerRadius;
  G4double tank_height;
  G4double tank_outerRadius;
  G4double tank_startingAngle;
  G4double tank_spanningAngle;

  G4double world_innerRadius;
  G4double world_outerRadius;
  G4double world_z;
  G4double world_startingAngle;
  G4double world_spanningAngle;
};

#endif /*CherenkovDetectorConstruction.hh*/
