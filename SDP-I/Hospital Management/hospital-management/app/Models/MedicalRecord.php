<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class MedicalRecord extends Model
{
    protected $fillable = [
        'diagnosis', 'treatment',
    ];

    public function patient()
    {
        return $this->belongsTo(Patient::class);
    }
}
