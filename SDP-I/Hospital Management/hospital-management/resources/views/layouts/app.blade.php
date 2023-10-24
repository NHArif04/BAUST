<!DOCTYPE html>
<html>
<head>
    <title>Hospital Management System</title>
</head>
<body>
    <header>
        <h1>Welcome to Your Hospital</h1>
        <nav>
            <ul>
                <li><a href="{{ route('home') }}">Home</a></li>
                <li><a href="{{ route('patients.index') }}">Patients</a></li>
                <li><a href="{{ route('appointments.index') }}">Appointments</a></li>
            </ul>
        </nav>
    </header>

    <main>
        @yield('content')
    </main>

    <footer>
        &copy; {{ date('Y') }} Your Hospital. All rights reserved.
    </footer>
</body>
</html>
