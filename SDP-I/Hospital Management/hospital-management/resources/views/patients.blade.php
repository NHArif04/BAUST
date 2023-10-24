@extends('layouts.app')

@section('content')
    <h1>Patients List</h1>
    <table>
        <thead>
            <tr>
                <th>ID</th>
                <th>First Name</th>
                <th>Last Name</th>
                <th>Age</th>
                <th>Blood Group</th>
                <th>Gender</th>
                <th>Actions</th>
            </tr>
        </thead>
        <tbody>
            @foreach($patients as $patient)
                <tr>
                    <td>{{ $patient->id }}</td>
                    <td>{{ $patient->firstName }}</td>
                    <td>{{ $patient->lastName }}</td>
                    <td>{{ $patient->age }}</td>
                    <td>{{ $patient->blood }}</td>
                    <td>{{ $patient->gender }}</td>
                    <td>
                        <a href="{{ route('patients.show', $patient->id) }}">View</a>
                        <a href="{{ route('patients.edit', $patient->id) }}">Edit</a>
                        <a href="{{ route('patients.destroy', $patient->id) }}">Delete</a>
                    </td>
                </tr>
            @endforeach
        </tbody>
    </table>
@endsection
