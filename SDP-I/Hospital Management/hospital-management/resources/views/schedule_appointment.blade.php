<!-- resources/views/schedule_appointment.blade.php -->
@extends('layouts.app')

@section('content')
<div class="container">
    <h1>Schedule an Appointment</h1>
    <form method="POST" action="{{ route('appointments.store') }}">
        @csrf
        <label for="doctorName">Doctor's Name:</label>
        <input type="text" name="doctorName" required><br>
        <!-- Add other appointment fields here -->
        <button type="submit">Schedule Appointment</button>
    </form>
</div>
@endsection
