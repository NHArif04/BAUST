@extends('layouts.app')

@section('content')
    <h1>Edit Appointment</h1>
    <form method="POST" action="{{ route('appointments.update', $appointment->id) }}">
        @csrf
        @method('PUT')

        <label for="doctorName">Doctor Name:</label>
        <input type="text" name="doctorName" value="{{ $appointment->doctorName }}" required>
        <br>
        <label for="patientName">Patient Name:</label>
        <input type="text" name="patientName" value="{{ $appointment->patientName }}" required>
        <br>
        <label for="date">Date:</label>
        <input type="date" name="date" value="{{ $appointment->date }}" required>
        <br>
        <label for="time">Time:</label>
        <input type="time" name="time" value="{{ $appointment->time }}" required>
        <br>
        <button type="submit">Update</button>
    </form>
@endsection
