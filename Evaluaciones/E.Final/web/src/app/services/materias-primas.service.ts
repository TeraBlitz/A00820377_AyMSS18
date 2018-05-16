import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { environment } from '../../environments/environment';

@Injectable()
export class MateriasPrimasService {
  constructor(private http: HttpClient) {}

  getMps() {
    return this.http.get(environment.apiUrl + '/materias-primas');
  }

  getMp(id: string) {
    return this.http.get(environment.apiUrl + '/materias-primas/' + id);
  }

  createMp(admin: any) {
    return this.http.post(environment.apiUrl + '/materias-primas', admin, {
      responseType: 'text'
    });
  }

  updateMp(admin: any) {
    return this.http.put(
      environment.apiUrl + '/materias-primas/' + admin.id,
      admin,
      {
        responseType: 'text'
      }
    );
  }

  deleteMp(id: string) {
    return this.http.delete(environment.apiUrl + '/materias-primas/' + id, {
      responseType: 'text'
    });
  }
}
