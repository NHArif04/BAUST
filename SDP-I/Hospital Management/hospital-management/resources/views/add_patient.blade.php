<!-- resources/views/add_patient.blade.php -->
@extends('layouts.app')

@section('content')
<div class="container">
    <h1>Add New Patient</h1>
    <form method="POST" action="{{ route('patients.store') }}">
        @csrf
        <label for="firstName">First Name:</label>
        <input type="text" name="firstName" required><br>
        <label for="lastName">Last Name:</label>
        <input type="text" name="lastName" required><br>
        <!-- Add other patient fields here -->
        <button type="submit">Add Patient</button>
    </form>
</div>
@endsection
