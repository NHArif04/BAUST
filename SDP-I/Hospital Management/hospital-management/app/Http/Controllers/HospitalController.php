<?php

namespace App\Http\Controllers;

use App\Appointment;
use App\MedicalRecord;
use App\Patient;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\Validator;
use Illuminate\Validation\Rule;

class HospitalController extends Controller {
    public function addPatient( Request $request ) {
        $validator = Validator::make( $request->all(), [
            'firstName' => 'required|string',
            'lastName'  => 'required|string',
            'age'       => 'required|integer',
            'blood'     => 'required|string',
            'gender'    => ['required', Rule::in( ['Male', 'Female'] )],
        ] );

        if ( $validator->fails() ) {
            return redirect()->back()->withInput()->withErrors( $validator );
        }

        $patient = new Patient;
        $patient->firstName = $request->input( 'firstName' );
        $patient->lastName = $request->input( 'lastName' );
        $patient->age = $request->input( 'age' );
        $patient->blood = $request->input( 'blood' );
        $patient->gender = $request->input( 'gender' );
        $patient->save();

        return redirect()->route( 'patient.index' )->with( 'success', 'Patient added successfully' );
    }

    public function scheduleAppointment( Request $request ) {
        $appointment = new Appointment;
        $appointment->doctorName = $request->input( 'doctorName' );
        $appointment->patientName = $request->input( 'patientName' );
        $appointment->date = $request->input( 'date' );
        $appointment->time = $request->input( 'time' );
        $appointment->save();
    }

    public function addMedicalRecord( Request $request ) {
        $medicalRecord = new MedicalRecord;
        $medicalRecord->diagnosis = $request->input( 'diagnosis' );
        $medicalRecord->treatment = $request->input( 'treatment' );

        $patient = Patient::find( $request->input( 'patient_id' ) );
        $patient->medicalRecords()->save( $medicalRecord );
    }

    public function displayMedicalRecord( $patientId ) {
        $patient = Patient::find( $patientId );
        $medicalRecords = $patient->medicalRecords;

        return view( 'medical_records', ['patient' => $patient, 'medicalRecords' => $medicalRecords] );
    }

    public function modifyPatientInformation( Request $request ) {
        $patient = Patient::find( $request->input( 'patient_id' ) );
        $patient->firstName = $request->input( 'firstName' );
        $patient->lastName = $request->input( 'lastName' );
        $patient->age = $request->input( 'age' );
        $patient->blood = $request->input( 'blood' );
        $patient->gender = $request->input( 'gender' );
        $patient->save();
    }

    public function generateReport( $patientId ) {
        $patient = Patient::find( $patientId );
        return view( 'report', ['patient' => $patient] );
    }
}
