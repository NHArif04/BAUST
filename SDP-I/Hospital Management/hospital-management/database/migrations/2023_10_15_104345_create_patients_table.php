<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

class CreatePatientsTable extends Migration {
    public function up() {
        Schema::create( 'patients', function ( Blueprint $table ) {
            $table->id();
            $table->string( 'firstName' );
            $table->string( 'lastName' );
            $table->integer( 'age' );
            $table->string( 'blood' );
            $table->enum( 'gender', ['Male', 'Female'] );
            $table->timestamps();
        } );
    }

    public function down() {
        Schema::dropIfExists( 'patients' );
    }
};
