@extends('layouts.app')

@section('content')
    <h1>Appointments List</h1>
    <table>
        <thead>
            <tr>
                <th>ID</th>
                <th>Doctor Name</th>
                <th>Patient Name</th>
                <th>Date</th>
                <th>Time</th>
                <th>Actions</th>
            </tr>
        </thead>
        <tbody>
            @foreach($appointments as $appointment)
                <tr>
                    <td>{{ $appointment->id }}</td>
                    <td>{{ $appointment->doctorName }}</td>
                    <td>{{ $appointment->patientName }}</td>
                    <td>{{ $appointment->date }}</td>
                    <td>{{ $appointment->time }}</td>
                    <td>
                        <a href="{{ route('appointments.show', $appointment->id) }}">View</a>
                        <a href="{{ route('appointments.edit', $appointment->id) }}">Edit</a>
                        <a href="{{ route('appointments.destroy', $appointment->id) }}">Delete</a>
                    </td>
                </tr>
            @endforeach
        </tbody>
    </table>
@endsection
