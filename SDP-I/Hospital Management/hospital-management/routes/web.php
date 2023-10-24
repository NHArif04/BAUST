<?php

use Illuminate\Support\Facades\Route;

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider and all of them will
| be assigned to the "web" middleware group. Make something great!
|
*/

Route::get('/patients', [HospitalController::class, 'displayPatients'])->name('patients.index');
Route::get('/patients/{id}', [HospitalController::class, 'displayMedicalRecord'])->name('patients.show');
Route::get('/patients/{id}/edit', [HospitalController::class, 'editPatient'])->name('patients.edit');
Route::post('/patients/{id}/update', [HospitalController::class, 'updatePatient'])->name('patients.update');
Route::delete('/patients/{id}', [HospitalController::class, 'deletePatient'])->name('patients.delete');
Route::get('/appointments', [HospitalController::class, 'displayAppointments'])->name('appointments.index');

// Define other routes as needed

// Example of creating a resourceful route for Patients
Route::resource('patients', HospitalController::class)->only(['create', 'store']);

// Example of creating a resourceful route for Appointments
Route::resource('appointments', HospitalController::class)->only(['create', 'store']);
