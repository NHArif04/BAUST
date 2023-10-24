@extends('layouts.app')

@section('content')
    <h1>Patient Detail</h1>
    <p>ID: {{ $patient->id }}</p>
    <p>First Name: {{ $patient->firstName }}</p>
    <p>Last Name: {{ $patient->lastName }}</p>
    <p>Age: {{ $patient->age }}</p>
    <p>Blood Group: {{ $patient->blood }}</p>
    <p>Gender: {{ $patient->gender }}</p>
    <a href="{{ route('patients.index') }}">Back to List</a>
@endsection
