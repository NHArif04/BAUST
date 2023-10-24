@extends('layouts.app')

@section('content')
    <h1>Appointment Detail</h1>
    <p>ID: {{ $appointment->id }}</p>
    <p>Doctor Name: {{ $appointment->doctorName }}</p>
    <p>Patient Name: {{ $appointment->patientName }}</p>
    <p>Date: {{ $appointment->date }}</p>
    <p>Time: {{ $appointment->time }}</p>
    <a href="{{ route('appointments.index') }}">Back to List</a>
@endsection
