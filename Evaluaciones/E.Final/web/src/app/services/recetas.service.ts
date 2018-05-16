import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { environment } from '../../environments/environment';

@Injectable()
export class RecetasService {
  constructor(private http: HttpClient) {}

  getRs() {
    return this.http.get(environment.apiUrl + '/recetas');
  }

  getR(id: string) {
    return this.http.get(environment.apiUrl + '/recetas/' + id);
  }

  createR(admin: any) {
    return this.http.post(environment.apiUrl + '/recetas', admin, {
      responseType: 'text'
    });
  }

  updateR(admin: any) {
    return this.http.patch(environment.apiUrl + '/recetas/' + admin.id, admin, {
      responseType: 'text'
    });
  }

  deleteR(id: string) {
    return this.http.delete(environment.apiUrl + '/recetas/' + id, {
      responseType: 'text'
    });
  }
}
