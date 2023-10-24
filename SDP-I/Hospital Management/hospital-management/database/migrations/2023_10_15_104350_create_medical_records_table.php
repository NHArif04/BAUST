<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

class CreateMedicalRecordsTable extends Migration {
    public function up() {
        Schema::create( 'medical_records', function ( Blueprint $table ) {
            $table->id();
            $table->unsignedBigInteger( 'patient_id' );
            $table->string( 'diagnosis' );
            $table->text( 'treatment' );
            $table->timestamps();

            $table->foreign( 'patient_id' )->references( 'id' )->on( 'patients' );
        } );
    }

    public function down() {
        Schema::dropIfExists( 'medical_records' );
    }
};
