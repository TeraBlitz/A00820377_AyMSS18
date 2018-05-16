import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { environment } from '../../environments/environment';

@Injectable()
export class AdminService {
  constructor(private http: HttpClient) {}

  getAdmins() {
    return this.http.get(environment.apiUrl + '/usuarios');
  }

  getAdmin(id: string) {
    return this.http.get(environment.apiUrl + '/usuarios/' + id);
  }

  createAdmin(admin: any) {
    return this.http.post(environment.apiUrl + '/usuarios/register', admin, {
      responseType: 'text'
    });
  }

  updateAdmin(admin: any) {
    return this.http.patch(
      environment.apiUrl + '/usuarios/' + admin.id,
      admin,
      {
        responseType: 'text'
      }
    );
  }

  deleteAdmin(id: string) {
    return this.http.delete(environment.apiUrl + '/usuarios/' + id, {
      responseType: 'text'
    });
  }

  login(credentials: any) {
    return this.http.post(environment.apiUrl + '/usuarios/login', credentials);
  }

  logout() {
    return this.http.post(
      environment.apiUrl + '/usuarios/logout',
      {},
      {
        responseType: 'text'
      }
    );
  }
}
