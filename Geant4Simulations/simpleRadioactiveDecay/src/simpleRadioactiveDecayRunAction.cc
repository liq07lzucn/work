// Bradley Manning

// Simple Radioactive Decay


#include "simpleRadioactiveDecayRunAction.hh"

//Initialise
simpleRadioactiveDecayRunAction::simpleRadioactiveDecayRunAction(simpleRadioactiveDecayDetectorConstruction* detector, simpleRadioactiveDecayPrimaryGeneratorAction* primary)
  : G4UserRunAction()
{
}

//Destructor
simpleRadioactiveDecayRunAction::~simpleRadioactiveDecayRunAction()
{
}

//Function to generate run
G4Run* simpleRadioactiveDecayRunAction::GenerateRun()
{
}

//Called at the BEGINNING of every run eg. "/run/beamOn 1" will visit this once.
//                                "/run/beamOn 10" will visit this once as well.
void simpleRadioactiveDecayRunAction::BeginOfRunAction(const G4Run*)
{
}

//Called at the END of every run
void simpleRadioactiveDecayRunAction::EndOfRunAction(const G4Run*)
{
}
